let openMenu_btn = document.querySelector(".open-menu-btn");
let closeMenu_btn = document.querySelector(".close-menu-btn");
let navLinks_ul = document.querySelector(".nav-links-ul");

openMenu_btn.addEventListener("click",()=>{
  navLinks_ul.classList.add("show-menu")
})
closeMenu_btn.addEventListener("click",()=>{
  navLinks_ul.classList.remove("show-menu")
})
