<?php
session_name("sauchat");
session_start();
$nick = $_POST["nick"];
if(isset($_POST["nick"])){
	include "../../config/db.php";
	$q = $db->prepare("CALL changeNick(:uid,:nick)");
	if($q->execute(array("uid" => $_SESSION['uid'], "nick" => $nick))){
			$_SESSION["nickname"] = $nick;
			echo json_encode(array("result" => "success"));
	}
	else echo json_encode(array("result" => "error-exec"));
	//gerçekten login
	//doğruysa sessiona yaz result:success yolla, yanlışsa result:wrong-code yolla.
}
else echo json_encode(array("result" => "error"));