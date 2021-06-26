<?php
namespace Flash;
session_start();

use Ratchet\MessageComponentInterface;
use Ratchet\ConnectionInterface;
require "User.php";
class Chat implements MessageComponentInterface {
    protected $clients;

    public function __construct() {
        $this->clients = new \SplObjectStorage;
    }

    public function onOpen(ConnectionInterface $conn) {
        // Store the new connection to send messages to later
        $this->clients->attach($conn);
		$querystring = $conn->httpRequest->getUri()->getQuery();
		echo $conn->httpRequest->getUri()->getQuery();
		parse_str($querystring, $queryarray);
		$user_object = new \User;
		if(isset($queryarray['t']))
        {
            $user_object->setToken($queryarray['t']);
			$user_object->setConnID($conn->resourceId);
			$user_object->setConnToDb($queryarray['t']);
            $user_object->updateFromToken();
			$this->user = $user_object;
            $user_id = $user_object->getUid();
            /*$data['status_type'] = '1';
			$data['uid'] = $user_id;*/
			

            // first, you are sending to all existing users message of 'new'
			foreach ($this->clients as $sclient)
            {
				//biri girdiğinde herkese herkes gitsin.
            foreach ($this->clients as $client)
            {
				$cliConn = $client->resourceId;
				$cliUser = \User::withConn($cliConn);
				$data['status_type'] = '1';
				$data['uid'] = $cliUser->getUid();
				echo $sclient->resourceId.":".$cliConn.":".$data['uid']."_";
                $sclient->send(json_encode($data)); //here we are sending a status-message
				$conn->send(json_encode($data));
            }
			}
			echo "New connection! ({$user_object->getSid()})\n";
        }
		else {
			echo "res";
		}

        //echo $_SESSION['sid']."New connection! ({$conn->resourceId})\n";
    }

    public function onMessage(ConnectionInterface $from, $msg) {
        $numRecv = count($this->clients) - 1;
		parse_str($from->httpRequest->getUri()->getQuery(),$res);
		$fromUser = \User::withToken($res['t']);
		
        echo sprintf('Connection %d - %s sending message "%s" to %d other connection%s' . "\n", $from->resourceId, $fromUser->getSid(), $msg, $numRecv, $numRecv == 1 ? '' : 's');
			
		$data = json_decode($msg,true);
		if($data['dataType'] == 'message'){
			//dbye de kaydet de.
			if($data['recType'] == 1){
				//kişiye mesaj
			$senderConn = $from->resourceId;
			$toReceiverUID = $data['receiver'];
			$senderUser = \User::withConn($senderConn);
			$toReceiverUser = \User::withUID($toReceiverUID);
			
			require_once dirname(__DIR__)."/api/chat/sendMessage.php";
			sendMessage($senderUser->getUid(),$data['recType'],$toReceiverUID,$data["message"]);
			//$toReceiverConn = $data['connid'];
			//$toReceiverUser = \User::withConn($toReceiverConn);
            foreach($this->clients as $client)
				{
					if($from == $client)
					{
						$data['from'] = $senderUser->getUid();
						$data["nick"] = $senderUser->getNick();
					}
					else
					{
						$data['from'] = $senderUser->getUid();
						$data["nick"] = $senderUser->getNick();
					}
					$data["date"] = date("H:i:s");
					if($client->resourceId == $toReceiverUser->getConnID() || $from == $client)
					{   
						echo $client->resourceId."==".$toReceiverUser->getConnID();
						$client->send(json_encode($data));
					}
				}
			}
			else if($data['recType'] == 2){
				//gruba meseaj
			$senderConn = $from->resourceId;
			$toReceiverUID = $data['receiver'];
			$senderUser = \User::withConn($senderConn);
			//$toReceiverUser = \User::withUID($toReceiverUID);
			//burada receiverUser diye bir şey yok.
			require_once dirname(__DIR__)."/api/chat/sendMessage.php";
			sendMessage($senderUser->getUid(),$data['recType'],$toReceiverUID,$data["message"]);
			
			require_once dirname(__DIR__)."/api/chat/getGroupUsers.php";
			$groupUsers = getGroupUsers($toReceiverUID);
			$gUsers = array();
			foreach($groupUsers as $gu){
				array_push($gUsers,$gu["connection_id"]);
			}
			
			echo "receiverGUID:".$toReceiverUID;
			print_r($gUsers);
			
			
			
			foreach ($this->clients as $client) {
				//if ($from !== $client) 
				{
					if(in_array($client->resourceId, $gUsers))
					{
						$data['from'] = $senderUser->getUid();
						$data["nick"] = $senderUser->getNick();
						$data["date"] = date("H:i:s");
						echo $client->resourceId.":::".json_encode($data);
						$client->send(json_encode($data));
					}
					//group
					}
				}
			}
			else if($data['recType']==0){
				//broadcast mesaj
			$senderConn = $from->resourceId;
			$toReceiverUID = $data['receiver'];
			$senderUser = \User::withConn($senderConn);
			$toReceiverUser = \User::withUID($toReceiverUID);
			
			require_once dirname(__DIR__)."/api/chat/sendMessage.php";
			sendMessage($senderUser->getUid(),$data['recType'],$toReceiverUID,$data["message"]);
			
			foreach ($this->clients as $client) {
				//if ($from !== $client) 
				{
					if($from == $client)
					{
						$data['from'] = 'Me';
					}
					else
					{
						$data['from'] = $senderUser->getNick();
					}
					$data["date"] = date("H:i:s");

					// The sender is not the receiver, send to each client connected
					$client->send(json_encode($data));
					}
				}
			}
		}
		//print_r($from);
		//if($data->type == 'auth') 
		//$conn['sid'] = $data->sid;
		/*$user_object = new ChatUser;
		$user_object->setUserId($data['userId']);
		$user_data = $user_object->get_user_data_by_id();
		$user_name = $user_data["user_name"];
		$data['dt'] = date('d-m-Y h:i:s');*/

        /*foreach ($this->clients as $client) {
            if ($from !== $client) {
                // The sender is not the receiver, send to each client connected
                $client->send($msg);
            }
        }*/
    }

    public function onClose(ConnectionInterface $conn) {
        // The connection is closed, remove it, as we can no longer send it messages
        $this->clients->detach($conn);
		
		parse_str($conn->httpRequest->getUri()->getQuery(), $res);
		
		$user = \User::withToken($res['t']);
        $data['status_type'] = '0';
        $data['uid'] = $user->getUid();
            foreach ($this->clients as $client)
            {
                $client->send(json_encode($data)); //here we are sending a status-message
            }
		
		$this->user->deleteToken();
        echo "Connection {$this->user->getSid()} has disconnected\n";
    }

    public function onError(ConnectionInterface $conn, \Exception $e) {
        echo "An error has occurred: {$e->getMessage()}\n";

        $conn->close();
    }
}