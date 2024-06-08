---
layout: page
title: Key Arhcive
permalink: /KeyArchive/
---
<!-- Blog Style Section with Embedded CSS -->
<style>
    .blog-style {
        width: 100%;
        margin: auto;
    }

    .blog-post {
        border-bottom: 1px solid #ccc;
        padding: 10px;
        display: flex;
        align-items: flex-start; /* 上对齐 */
    }

    .blog-post img {
        width: 150px; /* 图片宽度，根据需要调整 */
        height: 100px; /* 图片高度，根据需要调整 */
        margin-right: 20px; /* 右边距，根据需要调整 */
    }

    .post-details {
        flex-grow: 1;
    }
</style>

<div class="blog-style">
    {% for item in site.KeyArchive %}
    <div class="blog-post">
        <a href="{{ item.url | relative_url }}" title="{{ item.title }}">
            <img alt="" src="{{ item.img | relative_url }}">
            <div class="post-details">
                <h2>{{ item.title }}</h2>
                <p>{{ item.excerpt }}</p>
            </div>
        </a>
    </div>
    {% endfor %}
</div>