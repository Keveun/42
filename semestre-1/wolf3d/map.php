<?php
	$filename = "map";
	$file = file($filename, FILE_IGNORE_NEW_LINES);
	$height = str_pad(count($file), 4, "0", STR_PAD_LEFT);
	$width = str_pad((int)(strlen($file[0]) / 2) + 1, 4, "0", STR_PAD_LEFT);
	//echo "H: ", $height, ", W: ", $width, "\n
	$result = $height . "\0" . $width . "\0";
	foreach ($file as $line)
	{
		$pixels = explode (" ", $line);
		foreach ($pixels as $pixel)
			$result .= pack("C", $pixel);
	}
	file_put_contents("map.kpmap", $result);
?>
