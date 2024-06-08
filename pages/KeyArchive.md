---
layout: page
title: Key Arhcive
permalink: /KeyArchive/
---
This is the project homepage for Key Archive or Key CAS (actually, I'm not sure what to call it, but it's essentially a no-code web page editor).

I will update the progress of this project and some thoughts here.


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .call-out_img {
            /* Background image set via JavaScript based on screen width */
        }
    </style>
</head>
<body>
    <div class="home">
        <div id="main" class="call-out call-out_img">
            <h1>Change <code>header_text</code> in <code>_config.yml</code></h1>
        </div>

        <!-- Include blog content here -->
        <!-- For example, using an iframe or fetching blog content via AJAX -->

    </div>

    <script>
        document.addEventListener("DOMContentLoaded", function() {
            var imageUrl = "path/to/default/image.jpg"; // Default image URL
            var imageBase = imageUrl.slice(0, imageUrl.lastIndexOf('.'));
            var imageExtension = imageUrl.slice(imageUrl.lastIndexOf('.'));
            var responsiveImageUrl = imageUrl; // Fallback to default if no matches

            // Responsive image URLs
            if (window.innerWidth <= 576) {
                responsiveImageUrl = imageBase + '-small' + imageExtension;
            } else if (window.innerWidth <= 768) {
                responsiveImageUrl = imageBase + '-medium' + imageExtension;
            }

            // Set background image based on screen width
            var callOutImgDiv = document.querySelector('.call-out_img');
            if (callOutImgDiv) {
                callOutImgDiv.style.backgroundImage = 'url("' + responsiveImageUrl + '")';
            }
        });
    </script>
</body>
</html>

