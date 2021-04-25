<div style="text-align: left;">
    
<table class="table table-striped">

    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>

    <tbody>
        <?php foreach ($positions as $position)    { ?>
            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td>$<?= $position["price"] ?></td>
                <td>$<?= $position["total"] ?></td>
            </tr>
        <?php } ?>

        <!-- last row, CASH and TOTAL -->
            <tr>
                <td>CASH</td>
                <td>cash balance</td>
                <td></td>
                <td></td>
                <td>$<?= $cashs[0]["cash"] ?></td>
            </tr>
        
    </tbody>

</table>
</div>
<!--
<div style="text-align: center;">

-->