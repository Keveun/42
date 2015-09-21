<?php
	class Colors
	{
		private $foreground_colors = array();
		private $background_colors = array();
 
		public function __construct()
		{
			$this->foreground_colors['black'] = '0;30';
			$this->foreground_colors['dark_gray'] = '1;30';
			$this->foreground_colors['blue'] = '0;34';
			$this->foreground_colors['light_blue'] = '1;34';
			$this->foreground_colors['green'] = '0;32';
			$this->foreground_colors['light_green'] = '1;32';
			$this->foreground_colors['cyan'] = '0;36';
			$this->foreground_colors['light_cyan'] = '1;36';
			$this->foreground_colors['red'] = '0;31';
			$this->foreground_colors['light_red'] = '1;31';
			$this->foreground_colors['purple'] = '0;35';
			$this->foreground_colors['light_purple'] = '1;35';
			$this->foreground_colors['brown'] = '0;33';
			$this->foreground_colors['yellow'] = '1;33';
			$this->foreground_colors['light_gray'] = '0;37';
			$this->foreground_colors['white'] = '1;37';
			$this->background_colors['black'] = '40';
			$this->background_colors['red'] = '41';
			$this->background_colors['green'] = '42';
			$this->background_colors['yellow'] = '43';
			$this->background_colors['blue'] = '44';
			$this->background_colors['magenta'] = '45';
			$this->background_colors['cyan'] = '46';
			$this->background_colors['light_gray'] = '47';
		}
 
		public function getColor($string, $foreground_color = null, $background_color = null)
		{
			$colored_string = "";
			if (isset($this->foreground_colors[$foreground_color]))
				$colored_string .= "\033[" . $this->foreground_colors[$foreground_color] . "m";
			if (isset($this->background_colors[$background_color]))
				$colored_string .= "\033[" . $this->background_colors[$background_color] . "m";
			$colored_string .=  $string . "\033[0m";
			return $colored_string;
		}
 
		public function getForegroundColors()
		{
			return array_keys($this->foreground_colors);
		}
 
		public function getBackgroundColors()
		{
			return array_keys($this->background_colors);
		}
	}

	function rglob($pattern = '*', $path = '', $flags = 0)
	{
		$paths = glob($path . '*', GLOB_MARK | GLOB_ONLYDIR | GLOB_NOSORT);
		$files = glob($path . $pattern, $flags);
		foreach ($paths as $path)
			$files = array_merge($files,rglob($pattern, $path, $flags));
		return $files;
	}

	function	read_file($filename)
	{
		global $erreurs;

		$file = @fopen($filename, "r");
		$message = '';
		if ($file)
		{
			$i = 1;
			// Fonction autorisées
			$func_list = file('funclist', FILE_IGNORE_NEW_LINES);
			//$func_list = array("main", "write", "malloc", "sizeof", "free", "open", "close", "read");
			// Create new Colors class
			$c = new Colors();
			while (($line = fgets($file, 4096)) !== false)
			{
				preg_match_all("/(\b(?!ft_)\w+)\(/ixU", $line, $out);
				foreach ($out[1] as $error)
					if (!in_array($error, $func_list))
					{
						$message .= $c->getColor("Line " . $i . ":", "yellow", "null") . "\t" . $c->getColor($error . "()", "null", "null") . "\n";
						++$erreurs;
					}
				++$i;
			}
			if (!feof($file))
				echo "Erreur: fgets() a échoué\n";
			fclose($file);
		}
		return ($message);
	}
	
	function trait_files($argv)
	{
		global $erreurs;
		$c = new Colors();

		foreach ($argv as $filename)
		{
			if (!is_file($filename))
			{
				echo "\n", $c->getColor($filename . ":", "light_blue", "null"), "\n";
				echo $c->getColor("Le fichier \"" . $filename . "\" n'existe pas.\n", "red", "null");
				continue;
			}
			if (pathinfo($filename, PATHINFO_EXTENSION) == "c")
			{
				$message = read_file($filename);
				if ($message)
					echo "\n", $c->getColor($filename . ":", "light_blue", "null"), "\n", $message;
			}
		}
		echo "\n", (($erreurs) ? $c->getColor("Il y a " . $erreurs . " erreurs.", "light_red", "null") : $c->getColor("Il n'y a pas de fonctions interdites.", "light_green", "null")), "\n";
	}

	function main($argc, $argv)
	{
		if ($argc > 1)
		{
			if ($argv[1] == "-r")
				trait_files(rglob("*.c"));
			else
				trait_files($argc, $argv);
		}
		else
			echo "Utilisation: php checkfunc [-r] OU [nom du fichier] [nom du fichier...]\n";
	}

	main($argc, $argv);
?>
