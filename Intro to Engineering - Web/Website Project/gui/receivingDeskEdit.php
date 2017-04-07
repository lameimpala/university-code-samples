

<div class="container">
<div class="header">
	<legend>Edit Quantity</legend>
</div>
	<?php
		if (!isset($_GET['inItemID'])) {
			$item=$_SESSION['controller']->getProduct($_POST['inItemID']);
		} else {
			$item=$_SESSION['controller']->getProduct($_GET['inItemID']);
		}
		echo "<table style='width:70%''>";
		echo "<caption align='top'>Item Information</caption>";
		echo "<tr>";
		echo "<th>Item ID</th>";
		echo "<th>Item Description</th>";
		echo "<th>Current Quantity</th>";
		echo "</tr>";
		
		echo "<tr>";
		echo "<td>". $item->id . "</td>";
		echo "<td>". $item->description ."</td>";
		echo "<td>". $item->quantity ."</td>";
		echo "</table>";
		echo "<hr>";
		echo "<form method='POST' action='index.php?page=receivingDeskConfirm'>";
		echo "<p><b>Enter Received Quantity:</b><input class='form-control' type='text' name='newQty'></p>";
		echo "<p><input class='btn btn-primary btn-sm' type = 'submit'></p>";
		echo "<input name='id' value='". $item->id ."' style='display:none'>";
		echo "</form>";
		
	?>
</div>