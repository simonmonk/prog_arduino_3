char *index_template = "                              \
<script>                                              \
function get_reading() {                              \
  const request = new XMLHttpRequest();               \
  request.open('GET', '/touch');                      \
  request.send();                                     \
  request.onload = function() {                       \
    if (request.status === 200) {                     \
      value_got = request.responseText;               \
      field = document.getElementById('value_field'); \
      field.textContent = value_got;                  \
      window.setTimeout(get_reading, 500);            \
    }                                                 \
  }                                                   \
}                                                     \
get_reading();                                        \
                                                      \
</script>                                             \
<h1>Touch Value: <span id='value_field'/></h1>        \
";
