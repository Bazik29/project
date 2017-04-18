
// Всего страниц
var countPages = 2
// Текущая страница
var currenPage = 0
// Номера страниц теории
var theorypages = [0, 2]

// Проверка ответов
function test(number){
    switch(number){
        case 0:
        return (test_1.answer == 3);
        break;
        default:
            return false;
        break;
    }
}

function next(){
    if (test(currenPage)){
        if (currenPage < countPages) currenPage++;
        view.currentIndex = currenPage;
        title.text = "Угадал!";
    }
    else
        title.text = "Не угадал!";
}
function previous(){
    if (currenPage > 0) currenPage--;
    view.currentIndex = currenPage
}
