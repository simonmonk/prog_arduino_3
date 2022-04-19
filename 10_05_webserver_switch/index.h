char *index_template = "                              \
<script>                                              \
    function post_switch_status(state) {              \
        const request = new XMLHttpRequest();         \                 
        request.open('POST', '/switch');              \                  
        request.send(state.toString());               \                             
    }                                                 \
</script>                                             \                                           
                                                      \
<h1>Switch</h1>                                       \
<button onClick='post_switch_status(1)'>On</button>   \
<button onClick='post_switch_status(0)'>Off</button>  \
";
