<html>
<head>
	<title>
		Product System
	</title>

	<link href="css/bootstrap.min.css" rel="stylesheet">

    <link href="css/shop-homepage.css" rel="stylesheet">

	<script src='js/jquery.js'></script>
	<script src='js/bootstrap.min.js'></script>

<?php
function trace($text) {
	global $logText;
	$logText .= $text . '<br>';
}


if (!isset($_SESSION['controller'])) {
	$_SESSION['controller'] = new ShoppingController();
} else {
	trace("controller already in session");
}
if (!isset($_SESSION['controller2'])) {
	$_SESSION['controller2'] = new receivingDeskController();
} else {
	trace("controller already in session");
}
if (!isset($_SESSION['orderController'])) {
	$_SESSION['orderController'] = new orderController();
} else {
	trace("controller already in session");
}

?>
</head>