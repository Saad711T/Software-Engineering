-- استعلام عن أكثر الكتب تحتوي على نسخ
SELECT title, available_copies
FROM books
ORDER BY available_copies DESC
LIMIT 5;

-- استعلام عن المؤلفين الذين ولدوا بعد عام 1900
SELECT name, birth_year
FROM authors
WHERE birth_year > 1900;

-- استعلام عن عدد الكتب لكل تصنيف
SELECT genre, COUNT(*) AS total_books
FROM books
GROUP BY genre
ORDER BY total_books DESC;

-- استعلام عن الكتب المنشورة خلال القرن العشرين
SELECT title, publication_year
FROM books
WHERE publication_year BETWEEN 1900 AND 2000;

-- مجموع الكتب المتوفرة
SELECT SUM (available_copies) AS total_copies
