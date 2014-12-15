$(document).ready(function() {
  bindSongButtons();
});

function bindSongButtons() {
  $("img").click(function() {
  	$.post("/songs/"+this.id)
    //console.log(this.id)
});
}