<?php
session_name("sauchat");
session_start();
$myuid = $_SESSION["uid"];
$type = $_GET["type"];
$receiver = $_GET["id"];

include dirname(__DIR__) ."../../config/db.php";
$q = $db->prepare("CALL getMessages(:uid,:type,:receiver)");
$q->execute(array("uid" => $myuid, "type" => $type, "receiver"=>$receiver));
$f = $q->fetchAll(PDO::FETCH_ASSOC);
echo json_encode($f);