<?php
$id = $_GET['id'];

$product = $_SESSION['controller']->getProduct($id);

?>

<div class="container">



<?php
echo "<h2>" . $product->description . "</h2>";
echo "<h3>$" . $product->price . "</h3>";
echo "<hr>";
?>
<form method="post" action="index.php?page=submitOrder">
<input class="form-control" type="number" value="1" name="quantity" min="0" max="<?php echo $product->quantity?>"><br>
<input name="id" value="<?php echo $id?>" style="display:none">
<input class="btn btn-lg btn-primary" type="submit" value="Submit">
</form>
</div>