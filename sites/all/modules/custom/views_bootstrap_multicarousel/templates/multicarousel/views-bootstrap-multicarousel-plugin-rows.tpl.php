<div class="<?php print $row_classes ?>">
    <div class='well well-lg'>
    <?php if (!empty($title)): ?>
        <h4><?php print $title ?></h4>
    <?php endif ?>

    <?php print $image ?>

    <?php if (!empty($description)): ?>
        <p><?php print $description ?></p>
    <?php endif ?>
    </div>
</div>

