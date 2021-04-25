<?php //dump($perlist); // DEBUG ?>

<tr>
  <td >
    <div id="middle">
    <form action="agtpost.php" method="post">
        <fieldset>
            <legend><?= $perlist['place_name'] ?></legend>
            <div class="form-group">
                Property Name: <Input class="form-control" name="place_name" placeholder="Property Name" type="text" 
                value ="<?= $perlist['place_name'] ?>"/>
            </div>
            <div class="form-group">
                Postal Code: <input class="form-control" name="postal_code" placeholder="Postal Code" type="text" 
                value ="<?= $perlist['postal_code'] ?>"/>
            </div>
            <div class="form-group">
                Map Latitude: <input class="form-control" name="latitude" placeholder="Latitude" type="text"
                value ="<?= $perlist['latitude'] ?>"/>
            </div>
            <div class="form-group">
                Map Longitude: <input class="form-control" name="longitude" placeholder="Longitude" type="text"
                value ="<?= $perlist['longitude'] ?>"/>
            </div>
            <div class="form-group">
                Address: <input class="form-control" size="50" name="admin_name1" placeholder="Address" type="text"
                value ="<?= $perlist['admin_name1'] ?>"/>
            </div>
            <div class="form-group">
                Building Name: <input class="form-control" name="admin_name2" placeholder="Address" type="text"
                value ="<?= $perlist['admin_name2'] ?>"/>
            </div>
            <div class="form-group">
                Selling Price: <input class="form-control" name="price" placeholder="Price" type="number" value="<?=$perlist['price'] ?>"/>
            </div>
            <div class="form-group">
                Type: <input class="form-control" name="building" placeholder="Condo" type="text"
                value ="<?= $perlist['building'] ?>"/>
            </div>

            <div class="form-group">
                Year Start: <input class="form-control" name="yearstart" placeholder="Year Start" type="text"
                value ="<?= $perlist['yearstart'] ?>"/>
            </div>
            
            <div class="form-group">
                Free or Lease: <input class="form-control" name="freelease" placeholder="Lease" type="text"
                value ="<?= $perlist['freelease'] ?>"/>
            </div>
            

            <div class="form-group">
                Sqft: <input class="form-control" name="sqft" placeholder="Sqft" type="text"
                value ="<?= $perlist['sqft'] ?>"/>
            </div>
            
            <div class="form-group">
                No. of Bedroom: <input class="form-control" name="bedroom" placeholder="Bedroom" type="text"
                value ="<?= $perlist['bedroom'] ?>"/>
            </div>


            <div class="form-group">
                No. of bath: <input class="form-control" name="shower" placeholder="Shower" type="text"
                value ="<?= $perlist['shower'] ?>"/>
            </div>
            <div class="form-group">
                Paranomic Image: <input class="form-control" size="40" name="img_name" placeholder="Image" type="text"
                value ="<?= $perlist['img_name'] ?>"/>
            </div>
            
            <div class="form-group">
                Description (max 500 char):<br><textarea class="form-control" rows="4" cols="60" maxlength="500" name="description" placeholder="Description" 
                type="text"><?= $perlist['description'] ?></textarea>
            </div>
            
            <div class="form-group">
                <button class="btn btn-default" type="submit">
                    <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                    DONE ?
                </button>
            </div>
        </fieldset>
    </form>
    </div>

  </td>
</tr>
    <div id="middle">
            
<!--
            <div class="form-group">
                Description: <input class="form-control" name="admin_name3" placeholder="Description" type="text"
                maxlength="500" size="50" value ="<?= $perlist['admin_name3'] ?>"/>
            </div>
-->