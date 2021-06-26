<?php
session_name("sauchat");
session_start();
if($_GET["u"] == "fek"){
	$_SESSION["uid"] = 2;
	$_SESSION["sid"] = "G171210375";
	$_SESSION["nickname"] = "Fek";
	print_r($_SESSION);
}
else if($_GET["u"] == "oog"){
	$_SESSION["uid"] = 1;
	$_SESSION["sid"] = "G171210021";
	$_SESSION["nickname"] = "Onurgule";
	print_r($_SESSION);
}
