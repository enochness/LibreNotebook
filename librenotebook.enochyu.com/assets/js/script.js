var acc = document.getElementsByClassName("accordion");
var key = "toggle-" + location.pathname.split("/")[1];
var toggle = JSON.parse(sessionStorage.getItem(key) || "[]");

function openPanel(btn) {
  btn.classList.add("active");
  btn.nextElementSibling.style.maxHeight = "none";
}

for (var i = 0; i < acc.length; i++) {
  if (toggle.includes(acc[i].textContent.trim())) openPanel(acc[i]);

  acc[i].addEventListener("click", function() {
    var name = this.textContent.trim();
    var panel = this.nextElementSibling;
    this.classList.toggle("active");
    if (panel.style.maxHeight) {
      panel.style.maxHeight = null;
      toggle = toggle.filter(n => n !== name);
    } else {
      panel.style.maxHeight = panel.scrollHeight + "px";
      toggle.push(name);
    }
    sessionStorage.setItem(key, JSON.stringify(toggle));
  });
}

var current = document.querySelector('.left-toc a[href="' + location.pathname + '"]');
if (current && current.closest(".panel")) {
  openPanel(current.closest(".panel").previousElementSibling);
}

document.querySelectorAll(".panel-toggle").forEach(function (btn) {
  btn.addEventListener("click", function () {
    var name = "hide-" + btn.dataset.side;
    var hidden = document.documentElement.classList.toggle(name);
    try {
      if (hidden) localStorage.setItem(name, "1");
      else localStorage.removeItem(name);
    } catch (e) {}
  });
});


