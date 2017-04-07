<div class="container" style="width:800px">

<div style="display:block;width:350px;height:300px;float:left">
<h3>
From:
</h3>
<p>Sample Business<br>
123 Annie Glidden Dekalb</p>
</div>
<div style="display:inline-block;width:5px;height:300px;background-color:black;"></div>
<div style="display:block;width:350px;height:300px;float:right">




<h3>
To:
</h3>
<p><?php 
$order = $_SESSION['orderController']->getOrder($_GET['order']);
echo $order->name;
echo "<br>";
echo $order->address;
?>
</p>

</div>
<img src="images/barcode.png" height="350px" width="650px" style="display:inline-block"/>

</div>