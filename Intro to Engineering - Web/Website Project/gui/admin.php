
<div class="container">
<table class="table borderless table-borderless no-border">
    <tr>
        <th><font size = 4>Current Shipping Fee</font></th>
        <th><font size = 4>Current Tax Rate</font></th>
    </tr>
    <tr>
        <td><?php echo $_SESSION['controller']->getShippingFee(); ?></td>
        <td><?php echo $_SESSION['controller']->getSalesTax() *100 . '%'; ?></td>
    </tr>
</table>


<form action='index.php?page=adminConfirm' method="POST">
<p>
		        <label for="editShip" class="control-label">Enter new shipping fee ($12.00):</label>
            	<input class="form-control" type="text" value='<?php echo $_SESSION['controller']->getShippingFee(); ?>' class="form-control" id="editShip" name ="editShip" placeholder="New Shipping Fee">
</p>
<p>
		        <label for="editTax"  class="control-label">Enter new tax rate (6%):</label>
        
            	<input class="form-control" type="text" value='<?php echo $_SESSION['controller']->getSalesTax() *100; ?>' class="form-control" id="editTax" name ="editTax" placeholder="New Tax Rate">   


</p>
                <button type="submit" class="btn btn-primary">Submit</button>
</form>
</div>