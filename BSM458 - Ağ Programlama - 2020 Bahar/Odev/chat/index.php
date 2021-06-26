<?php 
session_name("sauchat");
session_start(); 
if(!isset($_SESSION['uid']) || $_SESSION['uid'] == ""){
	header("Location: http://onurgule.com.tr/flash/");
}
?>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
<script src="//maxcdn.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/sweetalert2@10.15.7/dist/sweetalert2.all.min.js"></script>
<link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.css" type="text/css" rel="stylesheet"/>
<link href="assets/css/style.css" rel="stylesheet" />
<?php
include "../api/user/setToken.php";
$uid = $_SESSION["uid"];
$token = uniqid();
setToken($uid,$token,1);
?>
<script>
var selectedType = 0;
var selectedRec = 0;
var conn = new WebSocket('ws://onurgule.com.tr:8080?t=<?=$token?>');

conn.onerror = function(e){
	document.getElementById('closed').style.display = 'block';
}
conn.onopen = function(e) {
    console.log("Connection established!");
	document.getElementById('wosocket').style.display = 'none';
	document.getElementById('wsocket').style.display = 'block';
};

</script>
</head>
<body>
<div id="wosocket" style="text-align:center; padding-top:150px;">
<h3>Sokete bağlanılıyor...</h3>
<h5>Sokete bağlanmadan mesajlaşmak pek hoş olmaz.</h5>
<p id="closed" style="color:red; display:none;">Sanırım soket kapalı, bu durumda mesajlaşmaya izin vermem mümkün değil.</p>
</div>
<div id="wsocket" style="display:none;">
<div class="container" style="margin-top:45px;">
<div class="" style="border:solid 1px #c4c4c4; padding:30px;">
<p><?=$_SESSION['nickname']?></p>
<p style="float:left;"><button class="btn btn-primary" onclick="changeNick()">Nick Değiştir</button></p>
<p style="float:right;"><button class="btn btn-danger" onclick="logout()">Çıkış Yap</button></p>
</div>
<div class="messaging">
      <div class="inbox_msg">
        <div class="inbox_people">
          <div class="headind_srch">
            <div class="recent_heading">
              <h4>Liste</h4>
            </div>
            <!--<div class="srch_bar">
              <div class="stylish-input-group">
                <input type="text" class="search-bar"  placeholder="Search" >
                <span class="input-group-addon">
                <button type="button"> <i class="fa fa-search" aria-hidden="true"></i> </button>
                </span> </div>
            </div>-->
          </div>
          <div class="inbox_chat">
		  <?php
		  include "../config/db.php";
		  $q = $db->prepare("CALL getPeople(:uid)");
		  $q->execute(array("uid" => $_SESSION['uid']));
		  $f=$q->fetchAll(PDO::FETCH_ASSOC);
		  foreach($f as $p){
		  ?>
            <div onclick="loadChat(<?=$p['Type']?>,<?=$p['Kisi']?>)" id="<?=$p['Type']."_".$p['Kisi']?>" class="chat_list <?php if($p['Type'] == 2 && $p['Kisi'] == 1){echo "active_chat";} ?>"> <!-- active-chat -->
              <div class="chat_people">
                <div class="chat_img"> 
				<? if($p['Type'] == 0 && $p['Kisi'] == 0){ ?>
				<img src="assets/img/broadcast.png" alt="Broadcast"> 
				<? } 
				else if ($p['Type'] == 2){?>
				<img src="https://icons.iconarchive.com/icons/xenatt/the-circle/256/App-Group-cobfig-icon.png" alt="Grup">
				<? }
				else if($p['Type'] == 1){?>
				<img src="https://ptetutorials.com/images/user-profile.png" alt="Kişi">
				<? } ?>
				</div>
                <div class="chat_ib">
                  <h5><?=$p['Name']?> <span id="<?=$p['Type']?>_<?=$p['Kisi']?>" class="chat_notif" style="color: red;border: indianred 1px;border-style: solid;border-radius: 50%;padding: 3px;"></span></h5>
                  <p><?=$p['Small']?> <? if($p['Type'] == 1){ ?><span class="user_status" id="<?=$p['Kisi']?>">Offline</span><? } ?></p>
                </div>
              </div>
            </div>
		  <? } ?>
          </div>
        </div>
        <div class="mesgs">
          <div class="msg_history" id="messages">
		  <? // incoming ve out var. o hesaplanır. Zaman falan yazılır solda tıklandığında ajax ile çekilir. buradayken socket
		  
		  ?>
            
          </div>
          <div class="type_msg">
            <div class="input_msg_write">
              <input type="text" class="write_msg" placeholder="Mesajınızı Yazın" />
              <button class="msg_send_btn" type="button"><i class="fa fa-paper-plane-o" aria-hidden="true"></i></button>
            </div>
          </div>
        </div>
      </div>
      
     
      
    </div></div>
	<div class="container">
	<h3>Gruplar</h3>
	<?
	include dirname(__DIR__)."/api/chat/getGroups.php";
	
	$groups = getGroups();
	foreach($groups as $g){
	?>
	<div class="group" style="padding: 20px 20px 40px 20px; border: solid 1px #c4c4c4; font-size: larger;">
	<div style="float:left;" class="group-name">
	<?=$g["Name"]?>
	</div>
	<div style="float:right;" class="group-button">
	<a href="../api/chat/toggleGroup.php?gid=<?=$g['GID']?>"><?=$g["inside"]==0?'Katıl':'Ayrıl'?></a>
	</div>
	</div>
	<? } ?>
	      <p class="text-center top_spac" style="margin-bottom:30px;"> 006 - F3K</p>
	</div>
	</div>
	<script>
	conn.onmessage = function(e) {
		let gel = JSON.parse(e.data);
				//console.log(gel);
		if(gel.status_type == 1){
			$('.user_status#'+gel.uid).css('color','green');
			$('.user_status#'+gel.uid).text("Online");
		}
		else {
			$('.user_status#'+gel.uid).css('color','grey');
			$('.user_status#'+gel.uid).text("Offline");
		}
		
		if(gel.dataType=='message'){
			if(gel.recType==0){
				if(gel.recType == selectedType && (gel.receiver == selectedRec || gel.from == selectedRec)){
					appendMsg(gel.recType,gel.from,gel.receiver,gel.message,gel.date,gel.nick);
				}
				else{
					let karsi = (<?=$_SESSION["uid"]?> == gel.receiver?gel.from:gel.receiver);
					increaseNotif(gel.recType,karsi);
				}
			}
			else if(gel.recType == 1){
				if(gel.recType == selectedType && (gel.receiver == selectedRec || gel.from == selectedRec)){
					appendMsg(gel.recType,gel.from,gel.receiver,gel.message,gel.date,gel.nick);
				}
				else{
					let karsi = (<?=$_SESSION["uid"]?> == gel.receiver?gel.from:gel.receiver);
					increaseNotif(gel.recType,karsi);
				}
			}
			else if(gel.recType == 2){
				if(gel.recType == selectedType && (gel.receiver == selectedRec || gel.from == selectedRec)){
					appendMsg(gel.recType,gel.from,gel.receiver,gel.message,gel.date,gel.nick);
				}
				else{
					let karsi = (<?=$_SESSION["uid"]?> == gel.receiver?gel.from:gel.receiver);
					increaseNotif(gel.recType,karsi);
				}
			}
		}
    //console.log(e.data);
	};
	function loadChat(type,id){
		$('#messages').html('');
		$('.active_chat').removeClass("active_chat");
		$('#'+type+'_'+id).addClass("active_chat");
		$('span#'+type+'_'+id+'.chat_notif').html('');
		selectedType = type;
		selectedRec = id;
		$.get('../api/chat/getMessages.php?type='+type+'&id='+id).then(function(gelen){
			let msgs = JSON.parse(gelen);
			msgs.forEach(function(a,b){
				appendMsg(a.Type,a.UID,a.Receiver,a.Message,a.Date,a.Nick);
			});
			//console.log(msgs);
			$('#messages')[0].scrollTop = $('#messages')[0].scrollHeight
		});
		
	}
	function appendMsg(type,from,to,msg,date,nick){
		//console.log(type,from,to,msg,date)
		//console.log(<?=$_SESSION['uid']?>, from == <?=$_SESSION["uid"]?>);
		if(from == <?=$_SESSION["uid"]?> || from == 'Me'){
			$('#messages').append('<div class="outgoing_msg"><div class="sent_msg"><p>'+msg+'</p><span class="time_date"> '+date+'</span></div></div>');
			//from me
		}
		else{
		$('#messages').append('<div class="incoming_msg"><div class="incoming_msg_img"> <img src="https://ptetutorials.com/images/user-profile.png" alt="sunil"> </div><div class="received_msg"><div class="received_withd_msg"><p>'+msg+'</p><span class="time_date">'+nick+' - '+date+'</span></div></div></div>');
		}
		$('#messages')[0].scrollTop = $('#messages')[0].scrollHeight
	}
	function increaseNotif(type,rec){
		var notif = $('span#'+type+'_'+rec+'.chat_notif').html()-0;
		notif++;
		$('span#'+type+'_'+rec+'.chat_notif').html(notif);
	}
	function sendMsg(rt,rc,ms){
		var msg = {
			dataType:'message',
			recType:rt,
			receiver:rc,
			message:ms
		};
		conn.send(JSON.stringify(msg));
	}
	$('.msg_send_btn').on( "click", function() {
		  let msg = $('.write_msg').val();
		  let rt = selectedType;
		  let rc = selectedRec;
		  sendMsg(rt,rc,msg);
		  $('.write_msg').val("");
		});
	var input = document.getElementsByClassName("write_msg")[0];

	// Execute a function when the user releases a key on the keyboard
	input.addEventListener("keyup", function(event) {
	  // Number 13 is the "Enter" key on the keyboard
	  if (event.keyCode === 13) {
		// Cancel the default action, if needed
		event.preventDefault();
		// Trigger the button element with a click
		document.getElementsByClassName("msg_send_btn")[0].click();
	  }
	});
	$(document).ready(function(){
		loadChat(selectedType, selectedRec);
	});
	async function changeNick(){
		Swal.fire({
		  title: 'Yeni nickinizi giriniz',
		  input: 'text',
		  inputAttributes: {
			autocapitalize: 'off'
		  },
		  showCancelButton: true,
		  confirmButtonText: 'Değiştir',
		  showLoaderOnConfirm: true,
		  preConfirm: async (nick) => {
			  Swal.disableInput();
			  Swal.showLoading(Swal.getDenyButton())
			  await $.post("../api/user/changeNick.php", {nick:nick},{"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36"}).then(ret => JSON.parse(ret)).then(res => {
				  console.log(res);
			if(res.result=='success'){
				document.location.reload();
			}
			else{
					Swal.showValidationMessage(
			  'Bir hata oluştu.'+res.result
			)
			}
		});
		  },
		  allowOutsideClick: () => !Swal.isLoading()
		});
	}
	function logout(){
		document.location.href='https://onurgule.com.tr/flash/api/user/logout.php';
	}
	</script>
    </body>
    </html>