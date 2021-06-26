<?php

function getGroupUsers($gid){
include dirname(__DIR__) ."../../config/db.php";
$q = $db->prepare("CALL getGroupUsers(:gid)");
$q->execute(array("gid" => $gid));
$f = $q->fetchAll(PDO::FETCH_ASSOC);
return $f;
}