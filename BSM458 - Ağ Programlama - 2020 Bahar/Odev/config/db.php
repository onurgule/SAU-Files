<?php
try{
	$db = new PDO("mysql:host=localhost;dbname=onurguletr_flash", "onurguletr_uflash","");
	$db->exec("SET NAMES 'utf8'; SET CHARSET 'utf8'");
}
catch(PDOException $e){
	print $e->getMessage();
}
?>