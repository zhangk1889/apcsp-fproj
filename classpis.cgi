#!/bin/bash

echo -e "Content-type: text/html\n\n"

echo "<h1>Check rpi status</h1>"

echo "<pre>$(./pisalive)</pre>"

