const sidebar = document.querySelector('#sidebar');
const menu = document.querySelector('#menu-button');

menu.addEventListener('click', () => {
  const open = sidebar.classList.toggle('open');
  menu.setAttribute('aria-expanded', String(open));
});

document.querySelectorAll('.sidebar a').forEach(link => {
  link.addEventListener('click', () => {
    sidebar.classList.remove('open');
    menu.setAttribute('aria-expanded', 'false');
  });
});

document.querySelectorAll('.copy').forEach(button => {
  button.addEventListener('click', async () => {
    const text = button.closest('.code-wrap').querySelector('code').innerText;
    await navigator.clipboard.writeText(text);
    button.textContent = 'Copied';
    setTimeout(() => { button.textContent = 'Copy'; }, 1200);
  });
});

const links = [...document.querySelectorAll('.sidebar a')];
const sections = links.map(a => document.querySelector(a.getAttribute('href'))).filter(Boolean);
const observer = new IntersectionObserver(entries => {
  entries.forEach(entry => {
    if (entry.isIntersecting) {
      links.forEach(a => a.classList.toggle('active', a.getAttribute('href') === `#${entry.target.id}`));
    }
  });
}, { rootMargin: '-15% 0px -75% 0px' });
sections.forEach(section => observer.observe(section));
