<div style="text-align: left;">
    
<table class="table table-striped">

    <thead>
        <tr>
            <th></th>
            <th></th>
            <th></th>
            <th></th>
        </tr>
    </thead>

    <tbody>
        </br>
        
        <div class="row" style="text-align: left">
        <?php foreach ($positions as $position)    { ?>
            <div class="col-sm-4">
                <a href="postpage.php?geo=<?= $position["place_name"] ?>">
                <img class="size-thumbnail" src="/buildphoto/<?= $position["img_name"] ?>" 
                width="160" height="90"></a></br>
                
                <strong><?= $position["place_name"] ?></strong></br>
                <?= $position["building"] ?></br>
                <?= $position["admin_name1"] ?></br>
                    
                <?= $position["bedroom"] ?> bedroom,  <?= $position["shower"] ?> shower </br>
                built <?= $position["yearstart"] ?> <?= $position["freelease"] ?></br>
                <?= $position["sqft"] ?> sqft | S$<?= $position["psf"] ?> psf </br>
                S$<?= $position["price"] ?>
                </br></br>
            </div>
        <?php } ?>
        </div>

    </tbody>

</table>
        <a href="login.php">Log in</a> to Edit or Add new listing.
</div>
