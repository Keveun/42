<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_to_kp.php                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <kperreau@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 17:19:54 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/31 17:19:57 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function	bmp_to_kp($filename, $dirname = "")
{
	// on récupere le fichier
	$file = file_get_contents($filename);

	// On convertit le binaire en hexa
	$temp = unpack("H*", $file);
	unset($file);
	$hex = $temp[1];
	unset($temp);

	// On récupere le header
	$header = substr($hex, 0, 108);
	if (substr($header, 0, 4) == "424d")
	{
		$header_parts = str_split($header, 2);
		$width = hexdec($header_parts[19].$header_parts[18]);
		$height = hexdec($header_parts[23].$header_parts[22]);
		unset($header_parts);
		unset($header); 
	}

	// On récupere le body
	$x = 0;
	$y = 1; 
	$body = substr($hex, 108);
	$body_size = (strlen($body) / 2);
	$header_size = ($width * $height);
	$usePadding = ($body_size > ($header_size * 3) + 4);
	$temp = '';
	$data = '';

	// On réécrit la data correctement, en partant d'en haut à gauche
	for ($i = 0; $i < $body_size; $i += 3)
	{
		if ($x >= $width)
		{
			if ($usePadding)
				$i += $width % 4;
			$x = 0;
			if (++$y > $height)
				break ;
		}
		$i_pos = $i * 2;
		$temp .= pack("C3",
					hexdec($body[$i_pos+4].$body[$i_pos+5]),
					hexdec($body[$i_pos+2].$body[$i_pos+3]),
					hexdec($body[$i_pos].$body[$i_pos+1])
				);
		if ($x + 1 == $width)
		{
			$data = $temp.$data;
			$temp = '';
		}
		++$x;
	}
	unset($body);

	// Resutat, hauteur + largeur + data
	$result = str_pad($height, 4, "0", STR_PAD_LEFT)."\0".str_pad($width, 4, "0", STR_PAD_LEFT)."\0".$data;
	unset($data);

	// Init le nom du fichier .kp
	$kpfile = basename($filename, '.bmp').".kp";

	// Ecrit/creer le fichier .kp
	if ($dirname)
		$kpfile = $dirname."/".$kpfile;
	file_put_contents($kpfile, $result);

	echo "Le fichier ", $kpfile, " a été créé avec succès.\n";
}

function main($argc, $argv)
{
	if ($argc > 1)
	{
		if (file_exists($argv[1]))
		{
			$ext = pathinfo($argv[1]);
			if ($ext['extension'] == "bmp")
				bmp_to_kp($argv[1], $ext['dirname']);
			else
				echo "Le fichier n'est pas un BMP.\n";
		}
		else
			echo "Le fichier n'existe pas.\n";
	}
	else
		echo "Entrez un fichier BMP.\n";
}

// On appel la fonction main
main($argc, $argv);
?>