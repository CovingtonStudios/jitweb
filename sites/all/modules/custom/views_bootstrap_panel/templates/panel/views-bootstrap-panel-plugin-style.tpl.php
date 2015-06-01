<div id="views-bootstrap-panel-<?php print $id ?>" class="<?php print $classes ?>">
  <?php foreach ($rows as $key => $row): ?>
    <div class="panel panel-default">
      <div class="panel-heading">
        <h3 class="panel-title">
            <?php print $titles[$key] ?>
        </h3>
      </div>

      <div class="panel-body">
            <?php print $bodies[$key] ?>
      </div>

    </div>
  <?php endforeach ?>
</div>
