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

    <tbody style="text-align: left">
        
        <?php //dump($perlist); // DEBUG; ?>

        <tr>
            <td></td>
            
            <td width="40%">
            <strong><?= $perlist["place_name"] ?></strong></br>
            <?= $perlist["building"] ?> - built <?= $perlist["yearstart"] ?> <?= $perlist["freelease"] ?></br>
            <?= $perlist["admin_name1"] ?></br>
            Postal Code: <?= $perlist["postal_code"] ?></br></td>
            
            <td width="40%">
            </br>
            <?= $perlist["bedroom"] ?> bedroom,  <?= $perlist["shower"] ?> shower </br>
            <?= $perlist["sqft"] ?> sqft | SGD$<?= (number_format(($perlist["price"]/$perlist["sqft"]), 2, '.', ',')) ?> psf</br>
            SGD$<?= (number_format($perlist["price"], 2, '.', ',' )) ?></td>
            
            <td></td>
        </tr>
    </tbody>
</table>
<table class="table table-striped">
    <tbody style="text-align: left">
        <tr>
            <td></td>
            <td width="80%">
                Description: <br><?= $perlist["description"] ?>
            </td>
            <td></td>
        </tr>
    </tbody>
</table>
</div>

<!--


-->