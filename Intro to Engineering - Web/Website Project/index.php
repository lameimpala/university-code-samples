<?php include 'php/session.php'; ?>
<!DOCTYPE html>
<html lang="en">

<?php include 'php/header.php'; ?>

<body>

<div id="layout">
	
	<?php include 'php/menu.php'; ?>

    <div id="main">
		<?php
			
			if (array_key_exists('page', $_REQUEST)) {
				$page = $_GET['page'];
			} else {
				$page = 'home';
			}
			include('gui/' . $page . '.php');
        ?>
	</div>
</div>

</body>
</html>
