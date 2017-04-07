

<div class="container">
<div class="header">
	<legend>Search Result</legend>
</div>
	<?php
		$item=$_SESSION['controller']->searchByDescription($_POST['inItemDesc']);
		echo "<table style='width:70%''>";
		echo "<caption align='top'>Item Information</caption>";
		echo "<tr>";
		echo "<th>Item ID</th>";
		echo "<th>Item Description</th>";
		echo "<th>Current Quantity</th>";
		echo "<th></th>";
		
		foreach($item as $item)
		{
		echo "<tr>";
		echo "<td>". $item->id . "</td>";
		echo "<td>". $item->description ."</td>";
		echo "<td>". $item->quantity ."</td>";
		echo "<td><a href='index.php?page=receivingDeskEdit&inItemID=" . $item->id . "' class='btn btn-primary btn-sm active' role='button' style='margin-right:35px'>Select</a></td>";

		}
		echo "</table>";
		
		
	?>
</div>