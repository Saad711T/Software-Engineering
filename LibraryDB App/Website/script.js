document.addEventListener("DOMContentLoaded", () => {
    const authorsGrid = document.getElementById("authors-grid");

    authorsGrid.innerHTML = authors.map(author => `
        <div class="author-card">
            <img src="${author.image}" alt="${author.name}">
            <h3>${author.name}</h3>
        </div>
    `).join("");
});
