--- 
layout: page
title : Rusted Warfare
permalink: /RustedWarfareMod/
subtitle: "Rusted Warfare" 
feature-img: "assets/img/pexels/computer.jpeg"
tags: [Page]
---

<!-- Portfolio Grid Section -->
<div class="portfolio-grid">
    {% for item in site.RustedWarfareMod %}
    <div class="portfolio-cell">
        <a class="portfolio-link" data-keyboard="true" href="{{ item.url | relative_url }}">
            <div class="caption" title="{{ item.title }}">
                <div class="caption-content">
                    <i class="fas fa-search-plus fa-3x"></i>
                </div>
            </div>
            <img alt="" class="" src="{{ item.img | relative_url }}">
        </a>
    </div>
    {% endfor %}
</div>