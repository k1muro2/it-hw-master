#include "ClientMode.h"
#include <algorithm>
void AutoBlock(CUserCmd* cmd);
matrix3x4_t fakelag[128];

bool sendpacket = false;

std::vector<std::string> msgs =
{
"Are you dumb, stupid, or dumb, huh?",
"Play me like a dummy, like bitch, are you dumbt",
"Suck my dick, fuckin bitch :D",
};

std::vector<std::string> trashtalk =
{
		"Несмотря на все свое население, в китае используется всего около 200 фамилий.",
		"В любое время в земной атмосфере происходит около 1800 гроз. Каждую секунду в землю ударяет 100 молний.",
		"Существует растение, которое называют цветком смеха. Оно вызывает беспричинный смех на полчаса.",
		"Люди с голубыми глазами лучше видят в темноте.",
		"Среднестатистическая женщина за свою жизнь успевает посидеть на 32 диетах.",
		"Самый старый обнаруженный рецепт супа датируется 6000 годом до нашей эры. Главный ингредиент — мясо бегемота.",
		"Жирафы в целях самозащиты действуют головой как молотком.",
		"В Швейцарии выпустили детские презервативы.",
		"Чихание при взгляде на солнце — это аутосомно-доминантный непроизвольный гелио-глазной синдром взрыва.",
		"Потребление йогурта в мире возросло за последние 12 лет в четыре раза.",
		"Самая старой кошкой на свете была Puss, из Англии, которая умерла в 1939 году через день после своего 36-ого дня рождения.",
		"На территории Японии 17 действующих вулканов.",
		"В Саудовской Аравии нет ни одной реки.",
		"В 1892 году в Италии девочкам стали разрешать выходить замуж начиная с 12 лет. Раньше этот возраст был еще меньше.",
		"Как минимум три часа в день мы бездельничаем.",
		"В большинстве реклам время показываемое на часах – 10:10, чтобы не закрывать марку часов.",
		"Имя шейха Хамада написано на Земле километровыми буквами и видно из космоса.",
		"В Албании кивание головой значит «нет», и наоборот.",
		"В Алабаме запрещено водить машину необутым. Закон, однако, позволяет ездить по встречной полосе, если включить фары.",
		"Комары могут летать во время дождя.",
		"У человека меньше мyскyлов, чем y гyсеницы.",
		"Браки, в которых жены плохо спят, имеют гораздо больше шансов развалиться.",
		"При сильной рвоте у человека могут лопнуть сосуды в глазах.",
		"За пол века овощи стали менее полезны.",
		"Япония — последняя страна в мире, формально сохранившая титул Империи.",
		"Бильярд, так же как и шахматы, имеет очень древнее происхождение, а его родиной является Азия.",
		"В Антарктиде банкоматов в 2 раза больше, чем постоянных жителей.",
		"Имя верблюда, изображенного на пачке сигарет «Camel» – Старый Джо.",
		"Пизанская башня никогда не была прямой!",
		"2 500 000 000 пицц производится в Италии ежегодно.",
		"Полярная крачка — единственная птица, которая мигрирует с одного полюса на другой.",
		"Самые большие в мире сластены-немцы и швйцарцы:согласно статистике, в год каждый из них съедает по 10-11 кг шоколада.",
		"Каждый американец имеет, в среднем, 7 пар джинсов.",
		"Самое популярное в мире женское имя - Анна. Его носят почти 100 миллионов женщин.",
		"По статистике сотовых операторов самая популярная смс 31 декабря: `Спасибо! А кто это?`",
		"Самая распространенная скальная порода на земле — это базальт.",
		"ДНК человека и банана совпадают на 50%.",
		"При ярком свете человек съедает намного меньше, чем с приглушённым тусклым освещением.",
		"Горькие напитки делают людей критичнее и строже.",
		"Гречка очищает желудок от жвачек.",
		"Лечебные свойства зелёного чая — это миф",
		"Лингвисты утверждают, что в любом языке есть слово, обозначающее подхалима.",
		"Длина самого длинного лимузина в мире — 30,5 метров",
		"На холоде насекомые дрожат, как и человек.",
		"Каждый день по всему миру выкуривают 15 миллиардов сигарет.",
		"Змея может спать в течение 3 лет.",
		"На Гавайях серфинг включен в школьную программу.",
		"В Швейцарии запрещено смывать воду в туалете после 10 часов вечера.",
		"Стрекозы в буквальном смысле до смерти боятся рыб.",
		"Женские сердца бьются быстрее, чем у мужчин.",
		"Примерно 10 000 птиц в год разбиваются об окна.",
		"Три силовых занятия в неделю дают наибольший эффект.",
		"Каучук – один из ингредиентов жевательной резинки. Благодаря ему мы можем надувать пузыри.",
		"Аисты могут засыпать в полете на 10-15 минут.",
		"По статистике 66% людей закрывают глаза во время поцелуя.",
		"Виадук Мийо - самый высокий мост в мире!",
		"13% людей притворяються, что говорят по мобильному телефону, что бы избежать неприятной встречи или разговора.",
		"В центре Мадрида есть отель из мусора.",
		"Пчелы никогда не спят. Пчела замирает на соте лишь на несколько секунд в течение суток.",
		"Пожилых людей больше всего в Швеции (24%) и меньше всего в Кувейте (2%).",
		"Булемия - это неукротимый аппетит.",
		"При улыбке у человека `работают` 17 мускулов.",
		"Самая дорогая пицца в мире стоит $1000",
		"Одна сигарета отнимает 5 минут жизни!",
		"Список подарков Сталину в честь его семидесятилетия печатался в советских газетах с декабря 1949 года по март 1953.",
		"Большинство американцев на вопрос `Сериал Вашего детства?` отвечают - «Зена: королева воинов»",
		"Японцы водят большие машины. Сити кары невозможно встретить даже в тесном Токио, зато джипов очень много.",
		"В 1988 году Мак Тайсон заработала за 91 секунду 20 миллионов долларов. За это время он нокаутировал Майкла Спинкса.",
		"Самый крупный рубин весит более 7 кг.",
		"Тайна Бермудского треугольника будоражит умы уже несколько столетий. Однако, есть на Земле и другие аномальные места.",
		"Cпособность сворачивать язык в трубочку передаётся генетически.",
		"У женщин почти всегда исчезают боли в суставах, стоит им забеременеть.",
		"Собаки африканской породы `Басенджи` не умеют лаять.",
		"В древнем Риме, мужчина принимая присягу или давая клятву, клал руку на мошонку.",
		"В Японии можно купить клубничные Cheetos.",
		"Полководец А. Македонский знал в лицо 30 000 солдат своего войска.",
		"Чувство усталости появляется при нагрузках 35-65% от абсолютных возможностей.",
		"Самый старый вулкан – Этна, его возраст более 350 000 лет.",
		"Когда вы краснеете, ваш желудок тоже краснеет.",
		"Во рту человека около 40 000 бактерий.",
		"Пузырьки в пиве «Гиннес» не поднимаются на поверхность, а опускаются на дно, в отличие от всех других сортов пива.",
		"У свиньи оргазм длится 30 минут!",
		"Термин «любовь» произошёл от «lubhyati» (санскрит) и означает «желание».",
		"Наполеон Бонапарт был вовсе не коротышкой — его рост был выше среднего в то время и составлял 169 сантиметров.",
		"35 см - таким был рост самого маленького пони. И звали его соответственно - тыквочка.",
		"Согласно британскому закону, принятому в 1845, попытка покончить жизнь самоубийством каралась смертной казнью.",
		"Петух не может петь, если не вытянет шею.",
		"По суше бегемот может бежать быстрее человека.",
		"Две трети жителей планеты Земля никогда не видели снега.",
		"Ласточка влетает в 5?ти сантиметровую щель на скорости 56 км/час.",
		"Кошка имеет 32 мускулы в каждом ухе.",
		"Самая дорогая пицца в мире стоит $1000.",
		"В Антарктиде найдено озеро, вода в котором в 11 раз солонее морской и может замерзнуть только при температуре -50 градусов",
		"Партенофобия - это боязнь девственниц.",
		"Почти каждый человек имел копилку в его/ее детстве, и в настоящее время эта традиция проддерживается.",
		"Пчела за свою жизнь производит всего 1-2 чайные ложки меда.",
		"Одна капля нефти делает непригодным для питья 25 литров воды.",
		"На Земле сейчас живут примерно сто тысяч человек в возрасте свыше ста лет.",
		"Ежедневно жители США съедают 18 гектаров пиццы.",
		"Эверест подрастает на 4 миллиметра в год.",
		"В Америке, американские горки называют русскими горками.",
		"Если кошки возле вас и у них вибрирует хвост они проявляют самое сильное чувство любви.",
		"Если стекло разбивается, трещины двигаться со скоростью до 3000 миль в час.",
		"Bugatti Veyron может проехать футбольное поле за одну секунду.",
		"Детеныши крокодила при рождении не имеют пола — он зависит от температуры кладки, где они будут развиваться и вылупляться.",
		"25% населения Индии с наивысшим IQ это больше чем все население США. В Индии больше умных детей чем в США вообще детей.",
		"Три силовых занятия в неделю дают наибольший эффект.",
		"Список подарков Сталину в честь его семидесятилетия печатался в советских газетах с декабря 1949 года по март 1953.",
		"Томас Эдисон, изобретатель лампочки, боялся темноты.",
		"У некоторых женщин может быть аллергия на сперму.",
		"Бабушку Леонардо Ди Каприо звали Елена Смирнова.",
		"Все полярные медведи - левши.",
		"У пчелы 2 желудка .Один для мёда ,другой для пищи.",
		"Общая длина государственной границы Ватикана составляет 3, 2 км.",
		"Cексуальность мужчины зависит от его схожести с обезьяной.",
		"Никогда не говори людям о своих проблемах, 80% ими не интересуются, остальные 20% рады что они у тебя есть!",
		"Одна британская компания делает мобильные телефоны, которые вместо звонков издают запахи.",
		"В Древней Греции салфетками служили листья фигового дерева, которыми рабы вытирали губы своему хозяину.",
		"С точки зрения эволюции человеческое обоняние бесполезно и, возможно, со временем исчезнет",
		"LSD не влияет на хромосомы.",
		"Рыба-доктор лечит людей, обгрызая чешуйки отмершей кожи пациентов.",
		"До 19 века шоколад употреблялся только в жидком виде. Плитки появились лишь в 1840-х годах.",
		"В Windows нельзя создать папку с названием `Con`.",
		"В среднем килограмм картофельных чипсов стоит в двести раз дороже, чем килограмм картофеля.",
		"У блондинов борода растет быстрее, чем у брюнетов.",
		"Отлично поднимает настроение физическая нагрузках.",
		"Писсуары, находящиеся в туалетах ближе к двери, как правило, самые чистые, так как их реже используют.",
		"Джулия Робертс — первая в истории киноактриса, получившая 20 миллионов долларов за роль в фильме.",
		"Американцы тратят больше денег на еду для своих собак,чем для своих детей.",
		"Ежедневно на Земле происходит тысячи слабых землетрясений.",
		"Япония — последняя страна в мире, формально сохранившая титул Империи.",
		"IQ-показатель людей, использующих IE, ниже, чем у пользователей других браузеров.",
		"В мире всего 7.1 % левшей.",
		"Подобно отпечаткам пальца, окрас жирафа также является уникальным",
		"В головном мозге человека за одну секунду происходит 100 000 химических реакций.",
		"Существуют реки, которые могут менять направление течения.",
		"В Швейцарии выпустили детские презервативы.",
		"Человеческое и свиное сердце практически полностью идентичны.",
		"У человека почти в 2 раза меньше извилин в коре головного мозга, чем у дельфина.",
		"У собак по четыре пальца на задних ногах, и по пять на передних.",
		"Человеческий глаз мигает в среднем 4 млн. 200 тыс. раз в год.",
		"На самом деле знаменитая фраза Суворова звучит так: «Тяжело в учении — легко в походе».",
		"Центр Евразии находится в Казахстане, в местечке Жидебай.",
		"Брань и сквернословие может уменьшать физическую боль.",
		"Статистика показывает, что в последнее время инициаторами развода все чаще становятся женщины.",
		"В 17 веке в Англии за ошибочный прогноз синоптиков подвергали смертной казни.",
		"Комары могут летать во время дождя.",
		"23 АВГУСТА - День Государственного Флага Украины.",
		"Сердце слона весит 20-30 кг и бьется с частотой 30 раз в минуту.",
		"Морская звезда может вывернуть свой желудок наизнанку.",
		"Джиму Керри сегодня исполнилось 50!",
		"Канада 4 раза за последние 5 лет была объявлена ООН лучшей для жизни страной.",
		"30% игроков NBA имеют татуировки.",
		"Человеческий глаз мигает в среднем 4 млн. 200 тыс. раз в год.",
		"Сегодня пользователи меняют свои фотографии в профилях соцсетей в 3 раза чаще, чем в 2006-ом году.",
		"Человеческий глаз мигает в среднем 4 млн. 200 тыс. раз в год.",
		"Сердцебиение может учащаться примерно на 30 процентов во время зевания.",
		"В Перу продаётся сок из лягушек.",
		"Чем чаще самец дрофы занимается сексом, тем быстрее он стареет.",
		"Глаза у страуса больше, чем его мозг.",
		"У слизней четыре носа.",
		"Гепард может бежать со скоростью до 130 км/ч",
		"В быстроте черный африканский носорог носорог не уступает лошади и может развивать скорость до 40 км/ч.",
		"В Минске есть станция метро «Московская», в Москве — «Киевская», а в Киеве — «Минская».",
		"Чаще всего жёны миллионеров — учителя.",
		"Одна сигарета отнимает 5 минут жизни!",
		"Жирафы в целях самозащиты действуют головой как молотком.",
		"Имя верблюда, изображенного на пачке сигарет «Camel» – Старый Джо.",
		"У медузы нет мозга и кровеносных сосудов.",
		"15% людей тайно грызут ногти.",
		"Каждый день по всему миру выкуривают 15 миллиардов сигарет.",
		"Компания Google купила компанию Motorola.",
		"Колличество смертей от различных несчастных случаев у мужчин в два раза выше, чем у женщин.",
		"Зелёный цвет успокаивает человека.",
		"В спиртных напитках можно найти 13 жизненно необходимых для нашего организма минеральных веществ.",
		"В г.Пара жители сверяют часы по дождю, т.к. ливни каждый день идут в одно и тоже время.",
		"Существуют картины и предметы из скотча.",
		"Во время чихания воздух из носа выходит со скоростью 400 км / ч.",
		"В 2007 году в Японии появилась в продаже лимитированная серия Pepsi со вкусом огурца.",
		"Самый большой в мире фотоаппарат имеет длину 11 метров",
		"Устрица умеет менять пол, чем не раз пользуется.",
		"Одна британская компания делает мобильные телефоны, которые вместо звонков издают запахи.",
		"Медведь гризли в день может поймать и съесть до 40.000 бабочек",
		"У пчел пять глаз.",
		"У Моны Лизы нет бровей.",
		"Слоны используют свой хобот для мастурбации",
		"В Японии можно купить клубничные Cheetos.",
		"Шахматы придумали в Индии.",
		"Самого быстрого репера в мире зовут Билгин Озчалкан (Ceza). Его рекорд 1267 слов за 2 минуты 40 секунд.",
		"Полное имя куклы Барби — Барбара Миллисент Робертс",
		"Слон – единственное животное которое помнит все.",
		"В Алабаме запрещено водить машину необутым. Закон, однако, позволяет ездить по встречной полосе, если включить фары.",
		"Самый быстрый мотоцикл в мире!Bub Seven Streamliner достиг средней скорости 590,63 км/ч и поставил новый рекорд.",
		"Кошка может издавать более 100 видов разных звуков, а собака только 10.",
		"В древнем Египте в знак траура по умершей кошке хозяин сбривал брови.",
		"В среднем, в понедельник люди жалуются на жизнь на 12 минут дольше, чем в другие дни.",
		"Булемия - это неукротимый аппетит.",
		"Человек за день тратит в среднем 3-4 часа на то, чтобы противостоять собственным желаниям.",
		"Умные дети гораздо чаще становятся алкоголиками.",
		"79% людей,чихнув говорят `ой`",
		"Чтобы нахмуриться, нужно задействовать больше мышц, чем для того, чтобы улыбнуться.",
		"Стоимость Земли — пять квадриллионов долларов.",
		"Февраль 1865 года — единственный месяц в истории человечества, в котором не было полнолуния.",
		"На Эйфелевой башне полностью обновляют краску каждые семь лет, причем вручную.",
		"Женщины в 4 раза ленивее, нежели мужчины.",
		"Книга – лучший лекарь при нервных расстройствах.",
		"Во Флориде запрещено петь на публике в купальнике.",
		"Осьминоги — самые умные животные среди беспозвоночных.",
		"Когда вы краснеете, ваш желудок краснеет тоже.",
		"Слово «горилла» переводится как «поросшая шерстью женщина»",
		"У человека меньше мyскyлов, чем y гyсеницы.",
		"В 1957 году была издана книга в которую вошли 117 рассказов очевидцев о визуальном контакте с Лох-Несским чудовищем",
		"Джонни Депп потерял девственность в 13 лет.",
		"В Зионе, штат Иллинойс, запрещено давать зажженную сигарету собаке, коту или другому домашнему животному.",
		"Если Википедию распечатать, то получится книга примерно с 30 000 000 страниц.",
		"В крупных московских супермаркетах во время ПИК ловят иногда до 20 клептоманов в час.",
		"Простая ласточка может пролететь в дверной зазор шириной 5 см на скорости 56 км/ч",
		"У сомов более 27 000 вкусовых рецепторов.",
		"Муравьи никогда не спят.",
		"Игуана может находиться под водой до 28 минут.",
		"По статистике, более 7000 человек получают травмы, упав со стула.",
		"В городе Буфорд (США) живёт всего один человек. Он работает и дворником и мэром.",
		"Крот может за одну ночь прорыть туннель длиной в 76 метров.",
		"Слёзы улучшают настроение только 30% людей.",
		"Кофе — это второй крупнейший товар в международной торговле после бензина.",
		"Взрослая свинья пробегает километр за 5 минут.",
		"Кошка может издавать более 100 видов разных звуков, а собака только 10.",
		"Облака не могут двигаться на юго-запад.",
		"Пчелы никогда не спят. Пчела замирает на соте лишь на несколько секунд в течение суток.",
		"Вам потребуется около 1000 лет, чтобы посмотреть все ролики на YouTube.",
		"В дикой природе лев убивает не больше 20 раз в год.",
		"Какапо – единственный в мире нелетающий попугай.",
		"100 граммов водки содержит 235 ккал.",
		"При улыбке у человека `работают` 17 мускулов.",
		"Стрекозы в буквальном смысле до смерти боятся рыб.",
		"Тайна Бермудского треугольника будоражит умы уже несколько столетий. Однако, есть на Земле и другие аномальные места.",
		"В Перу продаётся сок из лягушек.",
		"В том, что ударяться локтями так больно, виноват «весёлый нерв»",
		"В Японии, Тайване, Китае и Корее не принято целоваться у всех на виду.",
		"Риск смерти во время секса с любовницей значительно выше, чем с женой.",
		"Хомяки умеют подтягиваться,а некоторые даже переварачиваться через палочку.",
		"Во время зимней спячки сердце медведя на каждом выдохе останавливается на 15–20 сек.",
		"У Перис Хилтон 44 размер ноги.",
		"Самый распространенный мусор – сигаретные окурки. Ежегодно их выбрасывается 4.500.000.000 штук.",
		"Все полярные медведи - левши.",
		"Интернет увеличивает количество углерода в атмосфере и способствует глобальному потеплению.",
		"Если разбавить чай молоком, то можно почувствовать вкус сгущенного молока.",
		"Цвет носков правильно подбирать под цвет брюк, а не обуви.",
		"В дикой природе лев убивает не больше 20 раз в год.",
		"Для того, чтобы сфотографиться на первый фотоаппарат приходилось сидеть неподвижно около 8 часов."
};

void killmsg(IGameEvent* event)
{
	if (g_Options.misc_killmsg)
	{
		int attacker = g_EngineClient->GetPlayerForUserID(event->GetInt("attacker", 0));
		int dead = g_EngineClient->GetPlayerForUserID(event->GetInt("userid", 0));
		int me = g_EngineClient->GetLocalPlayer();
		if (attacker == me && dead)
		{
			g_EngineClient->ExecuteClientCmd("say 1");
		}
	}
}

void SetLocalPlayerReady()
{
	static auto SetLocalPlayerReadyFn = reinterpret_cast<bool(__stdcall*)(const char*)>(Utils::PatternScan(GetModuleHandleA("client.dll"), "55 8B EC 83 E4 F8 8B 4D 08 BA ? ? ? ? E8 ? ? ? ? 85 C0 75 12"));
	if (SetLocalPlayerReadyFn)
		SetLocalPlayerReadyFn("");
}
void aaccept() {
	typedef void(__cdecl* accept_t)(void);
	static accept_t accept = (accept_t)Utils::PatternScan(GetModuleHandleA("client.dll"),
		"55 8B EC 51 56 8B 35 ? ? ? ? 57 83 BE");

	if (accept && **(unsigned long**)((unsigned long)accept + 0x7)) {
		SetLocalPlayerReady();
	}
}

void autoaccept()
{
	auto match_session = g_match_framework->get_match_session();
	if (match_session) {
		auto session_settings = match_session->get_session_settings();
		if (session_settings) {

			//if (session_settings->GetString("game/mode", "competitive") || session_settings->GetString("game/mode", "wingman")) {

			std::string search_state = session_settings->GetString("game/mmqueue", "");

			if (search_state == "reserved") {
				FLASHWINFO fi;
				fi.cbSize = sizeof(FLASHWINFO);
				fi.hwnd = InputSys::Get().GetMainWindow();
				fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
				fi.uCount = 0;
				fi.dwTimeout = 0;
				FlashWindowEx(&fi);
				Sleep(500);
				aaccept();
			}
			//}
		}
	}
}
bool gitchance(float hitchance) {

	if (1 > hitchance)
		return true;

	float inaccuracy = g_LocalPlayer->m_hActiveWeapon()->GetInaccuracy();
	if (inaccuracy == 0) inaccuracy = 0.0000001;
	inaccuracy = 1 / inaccuracy;
	return inaccuracy > hitchance;
}
bool IsPlayerBehind(C_BasePlayer* player)
{
	Vector toTarget = (g_LocalPlayer->m_vecOrigin() - player->m_vecOrigin()).Normalized();
	Vector playerViewAngles;
	Math::AngleVectors(player->m_angEyeAngles(), playerViewAngles);
	if (toTarget.Dot(playerViewAngles) > -0.5f)
		return false;
	else
		return true;
}

void knifebot(CUserCmd* pCmd) {
	if (g_Options.kbot)
	{
		C_BaseCombatWeapon* pLocalWeapon = g_LocalPlayer->m_hActiveWeapon();
		if (pLocalWeapon && pLocalWeapon->GetCSWeaponData())
		{
			if (g_LocalPlayer->m_hActiveWeapon()->GetCSWeaponData()->iWeaponType == WEAPONTYPE_KNIFE)
			{

				for (int EntIndex = 1; EntIndex < g_EngineClient->GetMaxClients(); EntIndex++)
				{
					C_BasePlayer* Entity = (C_BasePlayer*)g_EntityList->GetClientEntity(EntIndex);

					if (!Entity)
						continue;

					if (!Entity->IsPlayer())
						continue;

					if (!Entity->IsAlive())
						continue;

					if (Entity == g_LocalPlayer)
						continue;

					float Distance = g_LocalPlayer->m_vecOrigin().DistTo(Entity->m_vecOrigin());

					if (Distance > 68)
						continue;

					if (Entity->m_iTeamNum() == g_LocalPlayer->m_iTeamNum())
						continue;

					Vector OrignWorld = Entity->m_vecOrigin();
					Vector OrignScreen;

					if (!Math::WorldToScreen(OrignWorld, OrignScreen))
						continue;

					static int cur_attack = 0;

					if (Distance > 60.f || Entity->m_iHealth() < 33)
						pCmd->buttons |= IN_ATTACK;
					else
					{
						if ((g_LocalPlayer->m_nTickBase() * g_GlobalVars->interval_per_tick) - pLocalWeapon->m_flNextPrimaryAttack() > 0)
						{
							if (!IsPlayerBehind(Entity)) {
								if (Entity->m_ArmorValue() > 0)
								{
									if (Entity->m_iHealth() > 61)
										pCmd->buttons |= IN_ATTACK;
									else
										pCmd->buttons |= IN_ATTACK2;
								}
								else
								{
									if (Entity->m_iHealth() < 33)
										pCmd->buttons |= IN_ATTACK;
									else
										pCmd->buttons |= IN_ATTACK2;
								}
							}
							else
								pCmd->buttons |= IN_ATTACK2;
						}

					}
				}
			}
		}
	}
}

QAngle vangle = QAngle();
float damage = 0.f;

#include <chrono>

void forcechangeregion()
{
	if (g_Options.misc_forceregion == 0)
		return;
	if (g_Options.misc_forceregion == 1) 
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster waw");
	if (g_Options.misc_forceregion == 2)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster atl");
	if (g_Options.misc_forceregion == 3)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster bom");
	if (g_Options.misc_forceregion == 4)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster can");
	if (g_Options.misc_forceregion == 5)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster canm");
	if (g_Options.misc_forceregion == 6)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster cant");
	if (g_Options.misc_forceregion == 7)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster canu");
	if (g_Options.misc_forceregion == 8)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster dxb");
	if (g_Options.misc_forceregion == 9)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster eat");
	if (g_Options.misc_forceregion == 10)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster fra");
	if (g_Options.misc_forceregion == 11)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster gru");
	if (g_Options.misc_forceregion == 12)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster hkg");
	if (g_Options.misc_forceregion == 13)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster iad");
	if (g_Options.misc_forceregion == 14)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster jnb");
	if (g_Options.misc_forceregion == 15)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster lax");
	if (g_Options.misc_forceregion == 16)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster lhr");
	if (g_Options.misc_forceregion == 17)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster lim");
	if (g_Options.misc_forceregion == 18)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster lux");
	if (g_Options.misc_forceregion == 19)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster maa");
	if (g_Options.misc_forceregion == 20)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster mad");
	if (g_Options.misc_forceregion == 21)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster man");
	if (g_Options.misc_forceregion == 22)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster okc");
	if (g_Options.misc_forceregion == 23)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster ord");
	if (g_Options.misc_forceregion == 24)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster par");
	if (g_Options.misc_forceregion == 25)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster pwg");
	if (g_Options.misc_forceregion == 26)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster pwj");
	if (g_Options.misc_forceregion == 27)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster pwu");
	if (g_Options.misc_forceregion == 28)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster pww");
	if (g_Options.misc_forceregion == 29)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster pwz");
	if (g_Options.misc_forceregion == 30)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster scl");
	if (g_Options.misc_forceregion == 31)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster sea");
	if (g_Options.misc_forceregion == 32)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster sgp");
	if (g_Options.misc_forceregion == 33)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster sha");
	if (g_Options.misc_forceregion == 34)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster sham");
	if (g_Options.misc_forceregion == 35)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster shat");
	if (g_Options.misc_forceregion == 36)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster shau");
	if (g_Options.misc_forceregion == 37)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster shb");
	if (g_Options.misc_forceregion == 38)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster sto");
	if (g_Options.misc_forceregion == 39)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster sto2");
	if (g_Options.misc_forceregion == 40)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster syd");
	if (g_Options.misc_forceregion == 41)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster tsn");
	if (g_Options.misc_forceregion == 42)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster tsnm");
	if (g_Options.misc_forceregion == 43)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster tsnt");
	if (g_Options.misc_forceregion == 44)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster tsnu");
	if (g_Options.misc_forceregion == 45)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster tyo");
	if (g_Options.misc_forceregion == 46)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster tyo1");
	if (g_Options.misc_forceregion == 47)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster vie");
	if (g_Options.misc_forceregion == 48)
		g_EngineClient->ExecuteClientCmd("sdr SDRClient_ForceRelayCluster ams");
}

void dmimmunity()
{
	if (g_Options.misc_immunity)
	{
		static DWORD g_dTimer = 0;
		if (GetTickCount() > g_dTimer + 850)
		{
			if (!g_LocalPlayer->IsAlive() || !g_LocalPlayer->IsPlayer())
			{
				g_EngineClient->ExecuteClientCmd("open_buymenu");
				g_dTimer = GetTickCount();
			}
		}
	}
}

void ChatSpammer() //ebat ELITNO suuuka
{
	if (g_Options.misc_chat_spammer == 1)
	{
		static DWORD g_dTimer = 0;
		if (GetTickCount() > g_dTimer + 850)
		{
			g_EngineClient->ExecuteClientCmd(u8"say ﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽﷽ ﷽﷽");
			g_dTimer = GetTickCount();
		}
	}

	if (g_Options.misc_chat_spammer == 2)
	{
		long curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		static long timestamp = curTime;

		if ((curTime - timestamp) < 850)
			return;

		if (g_Options.misc_chat_spammer)
		{
			if (msgs.empty())
				return;

			std::srand(time(NULL));

			std::string str;

			std::rotate(msgs.begin(), msgs.begin() + 1, msgs.end());

			str.append("say ");
			str.append(msgs[0].data());

			g_EngineClient->ExecuteClientCmd(str.c_str());
		}
		timestamp = curTime;
	}

	if (g_Options.misc_chat_spammer == 3)
	{
		long curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		static long timestamp = curTime;

		if ((curTime - timestamp) < 850)
			return;

		if (g_Options.misc_chat_spammer)
		{
			if (trashtalk.empty())
				return;

			std::srand(time(NULL));

			std::string str;

			std::rotate(trashtalk.begin(), trashtalk.begin() + 1, trashtalk.end());

			str.append("say ");
			str.append(trashtalk[0].data());

			g_EngineClient->ExecuteClientCmd(str.c_str());
		}
		timestamp = curTime;
	}
}

bool didSwitch = false;

void AutoWeapons(CUserCmd* cmd)
{
	C_BaseCombatWeapon* weapon = g_LocalPlayer->m_hActiveWeapon();

	if (!weapon) return;

	if (weapon->m_iClip1() <= 0 && !weapon->IsKnife() && cmd->buttons & IN_ATTACK)
	{
		auto type = g_LocalPlayer->m_hActiveWeapon();

		if ((weapon->m_iItemDefinitionIndex() == WEAPONTYPE_MACHINEGUN || weapon->m_iItemDefinitionIndex() == WEAPONTYPE_RIFLE || weapon->m_iItemDefinitionIndex() == WEAPONTYPE_SHOTGUN ||
			weapon->m_iItemDefinitionIndex() == WEAPONTYPE_SNIPER_RIFLE || weapon->m_iItemDefinitionIndex() == WEAPONTYPE_SUBMACHINEGUN) && !didSwitch) {
			g_EngineClient->ExecuteClientCmd("slot2");
			didSwitch = true;
		}
	}
	else
		didSwitch = false;
}

void SlideWalk(CUserCmd* cmd)
{
	if (g_LocalPlayer->m_nMoveType() == MOVETYPE_LADDER)
		return;

	if (cmd->forwardmove > 0)
	{
		cmd->buttons |= IN_BACK;
		cmd->buttons &= ~IN_FORWARD;
	}

	if (cmd->forwardmove < 0)
	{
		cmd->buttons |= IN_FORWARD;
		cmd->buttons &= ~IN_BACK;
	}

	if (cmd->sidemove < 0)
	{
		cmd->buttons |= IN_MOVERIGHT;
		cmd->buttons &= ~IN_MOVELEFT;
	}

	if (cmd->sidemove > 0)
	{
		cmd->buttons |= IN_MOVELEFT;
		cmd->buttons &= ~IN_MOVERIGHT;
	}
}
void Desync(CUserCmd* cmd, bool& send_packet);

float anglereal = 0.f;
float anglefake = 0.f;
void fix_movement(CUserCmd* cmd, QAngle& wishangle)
{
	Vector view_fwd, view_right, view_up, cmd_fwd, cmd_right, cmd_up;
	Math::AngleVectors(wishangle, view_fwd, view_right, view_up);
	Math::AngleVectors(cmd->viewangles, cmd_fwd, cmd_right, cmd_up);

	const auto v8 = sqrtf((view_fwd.x * view_fwd.x) + (view_fwd.y * view_fwd.y));
	const auto v10 = sqrtf((view_right.x * view_right.x) + (view_right.y * view_right.y));
	const auto v12 = sqrtf(view_up.z * view_up.z);

	const Vector norm_view_fwd((1.f / v8) * view_fwd.x, (1.f / v8) * view_fwd.y, 0.f);
	const Vector norm_view_right((1.f / v10) * view_right.x, (1.f / v10) * view_right.y, 0.f);
	const Vector norm_view_up(0.f, 0.f, (1.f / v12) * view_up.z);

	const auto v14 = sqrtf((cmd_fwd.x * cmd_fwd.x) + (cmd_fwd.y * cmd_fwd.y));
	const auto v16 = sqrtf((cmd_right.x * cmd_right.x) + (cmd_right.y * cmd_right.y));
	const auto v18 = sqrtf(cmd_up.z * cmd_up.z);

	const Vector norm_cmd_fwd((1.f / v14) * cmd_fwd.x, (1.f / v14) * cmd_fwd.y, 0.f);
	const Vector norm_cmd_right((1.f / v16) * cmd_right.x, (1.f / v16) * cmd_right.y, 0.f);
	const Vector norm_cmd_up(0.f, 0.f, (1.f / v18) * cmd_up.z);

	const auto v22 = norm_view_fwd.x * cmd->forwardmove;
	const auto v26 = norm_view_fwd.y * cmd->forwardmove;
	const auto v28 = norm_view_fwd.z * cmd->forwardmove;
	const auto v24 = norm_view_right.x * cmd->sidemove;
	const auto v23 = norm_view_right.y * cmd->sidemove;
	const auto v25 = norm_view_right.z * cmd->sidemove;
	const auto v30 = norm_view_up.x * cmd->upmove;
	const auto v27 = norm_view_up.z * cmd->upmove;
	const auto v29 = norm_view_up.y * cmd->upmove;

	cmd->forwardmove = ((((norm_cmd_fwd.x * v24) + (norm_cmd_fwd.y * v23)) + (norm_cmd_fwd.z * v25))
		+ (((norm_cmd_fwd.x * v22) + (norm_cmd_fwd.y * v26)) + (norm_cmd_fwd.z * v28)))
		+ (((norm_cmd_fwd.y * v30) + (norm_cmd_fwd.x * v29)) + (norm_cmd_fwd.z * v27));
	cmd->sidemove = ((((norm_cmd_right.x * v24) + (norm_cmd_right.y * v23)) + (norm_cmd_right.z * v25))
		+ (((norm_cmd_right.x * v22) + (norm_cmd_right.y * v26)) + (norm_cmd_right.z * v28)))
		+ (((norm_cmd_right.x * v29) + (norm_cmd_right.y * v30)) + (norm_cmd_right.z * v27));
	cmd->upmove = ((((norm_cmd_up.x * v23) + (norm_cmd_up.y * v24)) + (norm_cmd_up.z * v25))
		+ (((norm_cmd_up.x * v26) + (norm_cmd_up.y * v22)) + (norm_cmd_up.z * v28)))
		+ (((norm_cmd_up.x * v30) + (norm_cmd_up.y * v29)) + (norm_cmd_up.z * v27));

	const auto ratio = 2.f - fmaxf(fabsf(cmd->sidemove), fabsf(cmd->forwardmove)) / 450.f;
	cmd->forwardmove *= ratio;
	cmd->sidemove *= ratio;

	wishangle = cmd->viewangles;
}


float autozeus(CUserCmd* cmd)
{
	auto weapon = g_LocalPlayer->m_hActiveWeapon();
	if (!weapon)
		return 0;
	const auto weapon_data = weapon->GetCSWeaponData();
	if (!weapon_data)
		return 0;

	if (!(weapon->m_Item().m_iItemDefinitionIndex() == WEAPON_TASER))
		return 0;

	Ray_t ray;
	CGameTrace tr;
	CTraceFilterWorldAndPropsOnly filter;

	for (int i = 1; i < g_GlobalVars->maxClients; i++) {
		auto player = (C_BasePlayer*)g_EntityList->GetClientEntity(i);
		if (!player || !player->IsAlive() || player->IsDormant() || player == g_LocalPlayer || player->m_iTeamNum() == g_LocalPlayer->m_iTeamNum())
			continue;
		auto hitbox = player->GetHitboxPos(HITBOX_CHEST);

		const auto distance = g_LocalPlayer->GetEyePos().DistTo(hitbox);
		if (distance > weapon_data->flRange)
			continue;
		damage = weapon_data->iDamage * pow(weapon_data->flRangeModifier, distance / 500);
		if (damage < 120.f && damage < player->m_iHealth())
			continue;
		return damage;
	}
}

bool is_delayed = false;
float shot_delay_time;
bool shot_delay = false;
#include "../features/autowall.hpp"
void TriggerBot(CUserCmd* usercmd) {
	//if (!(g_LocalPlayer->m_hActiveWeapon()->m_Item().m_iItemDefinitionIndex() == WEAPON_TASER))
	if (g_Options.onkey && !GetAsyncKeyState(g_Options.trigbind)) {

		is_delayed = false;
		shot_delay = false;
		return;
	}
		
	std::vector<int> hitgroups;
	if (!(g_LocalPlayer->m_hActiveWeapon()->m_Item().m_iItemDefinitionIndex() == WEAPON_TASER)) {
		if (g_Options.trighead)
			hitgroups.push_back(HITGROUP_HEAD);
		if (g_Options.trigchest)
			hitgroups.push_back(HITGROUP_CHEST);
		if (g_Options.trigstomach)
			hitgroups.push_back(HITGROUP_STOMACH);
		if (g_Options.trigleftarm)
			hitgroups.push_back(HITGROUP_LEFTARM);
		if (g_Options.trigrightarm)
			hitgroups.push_back(HITGROUP_RIGHTARM);
		if (g_Options.trigleftleg)
			hitgroups.push_back(HITGROUP_LEFTLEG);
		if (g_Options.trigrightleg)
			hitgroups.push_back(HITGROUP_RIGHTLEG);
	}
	else {
		hitgroups.push_back(HITGROUP_CHEST);
		hitgroups.push_back(HITGROUP_STOMACH);
	}
	Vector rem, forward,
		src = g_LocalPlayer->GetEyePos();

	trace_t tr;
	Ray_t ray;
	CTraceFilter filter;
	filter.pSkip = g_LocalPlayer;

	QAngle viewangles = usercmd->viewangles;

	auto settings = g_Options.aimbot[g_LocalPlayer->m_hActiveWeapon()->m_Item().m_iItemDefinitionIndex()];

	QAngle rec;

	//rec.pitch = g_LocalPlayer->m_aimPunchAngle().pitch * (settings.rcs_x / 2) / 50;

	//viewangles += g_LocalPlayer->m_aimPunchAngle() * ((settings.rcs_x + settings.rcs_y) / 2) / 50;

	Math::AngleVectors(viewangles, forward);

	forward *= g_LocalPlayer->m_hActiveWeapon().Get()->GetCSWeaponData()->flRange;

	rem = src + forward;

	ray.Init(src, rem);

	UINT mask = MASK_SHOT | CONTENTS_GRATE;

	mask &= ~(CONTENTS_WINDOW);

	g_EngineTrace->TraceRay(ray, mask, &filter, &tr);

	if (!tr.hit_entity)
		return;
	bool dh = false;
	for (auto& hitgroupsorted : hitgroups) {
		if (tr.hitgroup == hitgroupsorted)
			dh = true;
	}
	auto player = reinterpret_cast<C_BasePlayer*>(tr.hit_entity);
	if (!player || player->IsDormant() || !player->IsAlive() || !player->IsPlayer())
		return;

	if (player->m_iTeamNum() == g_LocalPlayer->m_iTeamNum())
		return;

	if (g_Aimbot.IsLineGoesThroughSmoke(g_LocalPlayer->GetEyePos(), tr.endpos) && g_Options.trigchecksmoke)
		return;
	if (g_LocalPlayer->IsFlashed() && g_Options.trigcheckflash)
		return;
	//{
	//if (!g_Options.trigger_autostop)
	//	return;
	//usercmd->forwardmove = 10;
	//usercmd->sidemove = 10;
	//}
	//if()
	
	//if (!shot_delay) {
	if (dh && gitchance(g_Options.trighitchance))
	{
		if (!is_delayed && !shot_delay && g_Options.trigdelay > 0) {
			is_delayed = true;
			shot_delay = true;
			shot_delay_time = GetTickCount() + g_Options.trigdelay;
		}

		if (shot_delay && shot_delay_time <= GetTickCount()) {
			shot_delay = false;
		}

		if (!shot_delay) 
		{
			is_delayed = false;
			shot_delay = false;
			usercmd->buttons |= IN_ATTACK;
		}
	}
	else
	{
		shot_delay_time = 0.f;
		is_delayed = false;
		shot_delay = false;
	}
}

int max_choke_ticks() {

	int maxticks = (*g_GameRules && (*g_GameRules)->IsValveDS()) ? 11 : 15;
	static int max_choke_ticks = 0;
	static int latency_ticks = 0;
	float fl_latency = g_EngineClient->GetNetChannelInfo()->GetLatency(FLOW_OUTGOING);
	int latency = TIME_TO_TICKS(fl_latency);;
	if (g_ClientState->chokedcommands <= 0)
		latency_ticks = latency;
	else latency_ticks = std::max(latency, latency_ticks);

	if (fl_latency >= g_GlobalVars->interval_per_tick)
		max_choke_ticks = 11 - latency_ticks;
	else max_choke_ticks = 11;
	return max_choke_ticks;
}
void updatelby(CCSGOPlayerAnimState* animstate);

float GetFullLatency() {
	return g_EngineClient->GetNetChannelInfo()->GetLatency(FLOW_INCOMING) + g_EngineClient->GetNetChannelInfo()->GetLatency(FLOW_OUTGOING);
}

void Clantag()
{
	static bool restore = false;
	static float lastchangetime = 0.0;
	if (g_Options.misc_clantag_enabled && g_LocalPlayer) {
		if (g_Options.misc_clantag == 0)
		{
			restore = false;
			Utils::SetClantag("");
		}
		if (g_Options.misc_clantag == 1)
		{
			static auto was_on = false;

			if (!g_Options.misc_clantag_enabled) {
				if (was_on) Utils::SetClantag("");
				was_on = false;
				return;
			}

			was_on = true;

			static int prevtime;
			static int prevval;

			if (int(g_GlobalVars->curtime * 2.9) != prevtime) {
				if (prevval != int(g_GlobalVars->curtime * 4) % 34) {
					prevval = int(g_GlobalVars->curtime * 4) % 34;
					switch (int(g_GlobalVars->curtime * 4) % 34)
					{
					case 1: { Utils::SetClantag(" "); break; }
					case 2: { Utils::SetClantag("F "); break; }
					case 3: { Utils::SetClantag("Fo "); break; }
					case 4: { Utils::SetClantag("For "); break; }
					case 5: { Utils::SetClantag("Froz "); break; }
					case 6: { Utils::SetClantag("Forza "); break; }
					case 7: { Utils::SetClantag("Forzah "); break; }
					case 8: { Utils::SetClantag("Forzaho "); break; }
					case 9: { Utils::SetClantag("Forzahoo "); break; }
					case 10: { Utils::SetClantag("Forzahook "); break; }
					case 11: { Utils::SetClantag("Forzahook "); break; }
					case 12: { Utils::SetClantag("Forzahook "); break; }
					case 13: { Utils::SetClantag("/orzahook "); break; }
					case 14: { Utils::SetClantag("//rzahook "); break; }
					case 15: { Utils::SetClantag("///zahook "); break; }
					case 16: { Utils::SetClantag("////hook "); break; }
					case 17: { Utils::SetClantag("_////ook "); break; }
					case 18: { Utils::SetClantag("__////ok "); break; }
					case 19: { Utils::SetClantag("___////k "); break; }
					case 20: { Utils::SetClantag("____//// "); break; }
					case 21: { Utils::SetClantag("_____/// "); break; }
					case 22: { Utils::SetClantag("______// "); break; }
					case 23: { Utils::SetClantag("_______/ "); break; }
					case 24: { Utils::SetClantag("________ "); break; }
					case 25: { Utils::SetClantag("_______ "); break; }
					case 26: { Utils::SetClantag("______ "); break; }
					case 27: { Utils::SetClantag("_____ "); break; }
					case 28: { Utils::SetClantag("____ "); break; }
					case 29: { Utils::SetClantag("____ "); break; }
					case 30: { Utils::SetClantag("___ "); break; }
					case 31: { Utils::SetClantag("__ "); break; }
					case 32: { Utils::SetClantag("_ "); break; }
					case 33: { Utils::SetClantag(" "); break; }
					default:;
					}
				}
			}

			prevtime = int(g_GlobalVars->curtime);
		}
		if (g_Options.misc_clantag == 2)
		{
			static auto was_on = false;

			if (!g_Options.misc_clantag_enabled) {
				if (was_on) Utils::SetClantag("");
				was_on = false;
				return;
			}

			was_on = true;

			static int prevtime;
			static int prevval;

			if (int(g_GlobalVars->curtime * 2.9) != prevtime) {
				if (prevval != int(g_GlobalVars->curtime) % 27) {
					prevval = int(g_GlobalVars->curtime) % 27;
					switch (int(g_GlobalVars->curtime) % 27)
					{
					case 1: { Utils::SetClantag("                  "); break; }
					case 2: { Utils::SetClantag("                ga"); break; }
					case 3: { Utils::SetClantag("               gam"); break; }
					case 4: { Utils::SetClantag("              game"); break; }
					case 5: { Utils::SetClantag("             games"); break; }
					case 6: { Utils::SetClantag("            gamese"); break; }
					case 7: { Utils::SetClantag("           gamesen"); break; }
					case 8: { Utils::SetClantag("          gamesens"); break; }
					case 9: { Utils::SetClantag("         gamesense"); break; }
					case 10: { Utils::SetClantag("        gamesense "); break; }
					case 11: { Utils::SetClantag("       gamesense  "); break; }
					case 12: { Utils::SetClantag("      gamesense   "); break; }
					case 13: { Utils::SetClantag("     gamesense    "); break; }
					case 14: { Utils::SetClantag("    gamesense     "); break; }
					case 15: { Utils::SetClantag("   gamesense      "); break; }
					case 16: { Utils::SetClantag("  gamesense       "); break; }
					case 17: { Utils::SetClantag(" gamesense        "); break; }
					case 18: { Utils::SetClantag("gamesense         "); break; }
					case 19: { Utils::SetClantag("amesense          "); break; }
					case 20: { Utils::SetClantag("mesense           "); break; }
					case 21: { Utils::SetClantag("esense            "); break; }
					case 22: { Utils::SetClantag("sense             "); break; }
					case 23: { Utils::SetClantag("ense              "); break; }
					case 24: { Utils::SetClantag("nse               "); break; }
					case 25: { Utils::SetClantag("se                "); break; }
					case 26: { Utils::SetClantag("e                 "); break; }
					case 27: { Utils::SetClantag("                  "); break; }
					default:;
					}
				}
			}

			prevtime = int(g_GlobalVars->curtime);
		}
		if (g_Options.misc_clantag == 3)
		{
			if (g_GlobalVars->curtime + (GetFullLatency() / 2) - lastchangetime >= 0.35f)
			{

				std::string Name;

				if (g_Options.misc_customclan && g_Options.customclan && g_Options.customclan[0] && g_Options.misc_clantaga)
					Name = g_Options.customclan;
				else
					if (!g_Options.misc_customclan)
						Name = _xor_("NEVERLOSE ").c_str();
					else
						Name = _xor_(" ").c_str();

				Utils::SetClantag(Name.substr(0, int(g_GlobalVars->curtime + (GetFullLatency() / 2)) % Name.length()).c_str());
				lastchangetime = (g_GlobalVars->curtime + (GetFullLatency() / 2));
				restore = true;
			}
		}
		if (g_Options.misc_clantag == 4)
		{
			if (g_GlobalVars->curtime + (GetFullLatency() / 2) - lastchangetime >= 0.35f)
			{

				std::string Name;

				if (g_Options.misc_customclan && g_Options.customclan && g_Options.customclan[0] && g_Options.misc_clantaga)
					Name = g_Options.customclan;
				else
					if (!g_Options.misc_customclan)
						Name = _xor_("fatality ").c_str();
					else
						Name = _xor_(" ").c_str();

				Utils::SetClantag(Name.substr(0, int(g_GlobalVars->curtime + (GetFullLatency() / 2)) % Name.length()).c_str());
				lastchangetime = (g_GlobalVars->curtime + (GetFullLatency() / 2));
				restore = true;
			}
		}
		if (g_Options.misc_clantag == 5)
		{
			static auto was_on = false;

			if (!g_Options.misc_clantag_enabled) {
				if (was_on) Utils::SetClantag("");
				was_on = false;
				return;
			}

			was_on = true;

			static int prevtime;
			static int prevval;

			if (int(g_GlobalVars->curtime * 2.9) != prevtime) {
				if (prevval != int(g_GlobalVars->curtime * 4) % 210) {
					prevval = int(g_GlobalVars->curtime * 4) % 210;
					switch (int(g_GlobalVars->curtime * 4) % 210)
					{
					case 1: { Utils::SetClantag("_"); break; }
					case 2: { Utils::SetClantag("__"); break; }
					case 3: { Utils::SetClantag("___"); break; }
					case 4: { Utils::SetClantag("____"); break; }
					case 5: { Utils::SetClantag("_____"); break; }
					case 6: { Utils::SetClantag("______"); break; }
					case 7: { Utils::SetClantag("_______"); break; }
					case 8: { Utils::SetClantag("________"); break; }
					case 9: { Utils::SetClantag("_________"); break; }
					case 10: { Utils::SetClantag("________1"); break; }
					case 11: { Utils::SetClantag("_______10"); break; }
					case 12: { Utils::SetClantag("______100"); break; }
					case 13: { Utils::SetClantag("_____1000"); break; }
					case 14: { Utils::SetClantag("____1000-"); break; }
					case 15: { Utils::SetClantag("___1000-7"); break; }
					case 16: { Utils::SetClantag("__1000-7_"); break; }
					case 17: { Utils::SetClantag("_1000-7__"); break; }
					case 18: { Utils::SetClantag("1000-7___"); break; }
					case 19: { Utils::SetClantag("000-7____"); break; }
					case 20: { Utils::SetClantag("00-7____9"); break; }
					case 21: { Utils::SetClantag("0-7____99"); break; }
					case 22: { Utils::SetClantag("-7____993"); break; }
					case 23: { Utils::SetClantag("7____993-"); break; }
					case 24: { Utils::SetClantag("____993-7"); break; }
					case 25: { Utils::SetClantag("___993-7_"); break; }
					case 26: { Utils::SetClantag("__993-7__"); break; }
					case 27: { Utils::SetClantag("_993-7___"); break; }
					case 28: { Utils::SetClantag("993-7____"); break; }
					case 29: { Utils::SetClantag("93-7_____"); break; }
					case 30: { Utils::SetClantag("3-7_____9"); break; }
					case 31: { Utils::SetClantag("-7_____98"); break; }
					case 32: { Utils::SetClantag("7_____986"); break; }
					case 33: { Utils::SetClantag("_____986-"); break; }
					case 34: { Utils::SetClantag("____986-7"); break; }
					case 35: { Utils::SetClantag("___986-7_"); break; }
					case 36: { Utils::SetClantag("__986-7__"); break; }
					case 37: { Utils::SetClantag("_986-7___"); break; }
					case 38: { Utils::SetClantag("986-7____"); break; }
					case 39: { Utils::SetClantag("86-7____9"); break; }
					case 40: { Utils::SetClantag("6-7____97"); break; }
					case 41: { Utils::SetClantag("-7____979"); break; }
					case 42: { Utils::SetClantag("7____979-"); break; }
					case 43: { Utils::SetClantag("____979-7"); break; }
					case 44: { Utils::SetClantag("___979-7_"); break; }
					case 45: { Utils::SetClantag("__979-7__"); break; }
					case 46: { Utils::SetClantag("_979-7___"); break; }
					case 47: { Utils::SetClantag("979-7____"); break; }
					case 48: { Utils::SetClantag("79-7____9"); break; }
					case 49: { Utils::SetClantag("9-7____97"); break; }
					case 50: { Utils::SetClantag("-7____972"); break; }
					case 51: { Utils::SetClantag("7____972-"); break; }
					case 52: { Utils::SetClantag("____972-7"); break; }
					case 53: { Utils::SetClantag("___972-7_"); break; }
					case 54: { Utils::SetClantag("__972-7__"); break; }
					case 55: { Utils::SetClantag("_972-7___"); break; }
					case 56: { Utils::SetClantag("972-7____"); break; }
					case 57: { Utils::SetClantag("72-7____9"); break; }
					case 58: { Utils::SetClantag("2-7____96"); break; }
					case 59: { Utils::SetClantag("-7____965"); break; }
					case 60: { Utils::SetClantag("7____965-"); break; }
					case 61: { Utils::SetClantag("____965-7"); break; }
					case 62: { Utils::SetClantag("___965-7_"); break; }
					case 63: { Utils::SetClantag("__965-7__"); break; }
					case 64: { Utils::SetClantag("_965-7___"); break; }
					case 65: { Utils::SetClantag("65-7____9"); break; }
					case 66: { Utils::SetClantag("5-7____95"); break; }
					case 67: { Utils::SetClantag("-7____958"); break; }
					case 68: { Utils::SetClantag("7____958-"); break; }
					case 69: { Utils::SetClantag("____958-7"); break; }
					case 70: { Utils::SetClantag("___958-7_"); break; }
					case 71: { Utils::SetClantag("__958-7__"); break; }
					case 72: { Utils::SetClantag("_958-7___"); break; }
					case 73: { Utils::SetClantag("958-7____"); break; }
					case 74: { Utils::SetClantag("58-7____9"); break; }
					case 75: { Utils::SetClantag("8-7____95"); break; }
					case 76: { Utils::SetClantag("-7____951"); break; }
					case 77: { Utils::SetClantag("7____951-"); break; }
					case 78: { Utils::SetClantag("____951-7"); break; }
					case 79: { Utils::SetClantag("___951-7_"); break; }
					case 80: { Utils::SetClantag("__951-7__"); break; }
					case 81: { Utils::SetClantag("_951-7___"); break; }
					case 82: { Utils::SetClantag("951-7____"); break; }
					case 83: { Utils::SetClantag("51-7____9"); break; }
					case 84: { Utils::SetClantag("1-7____94"); break; }
					case 85: { Utils::SetClantag("-7____944"); break; }
					case 86: { Utils::SetClantag("7____944-"); break; }
					case 87: { Utils::SetClantag("____944-7"); break; }
					case 88: { Utils::SetClantag("___944-7_"); break; }
					case 89: { Utils::SetClantag("__944-7__"); break; }
					case 90: { Utils::SetClantag("_944-7___"); break; }
					case 91: { Utils::SetClantag("944-7____"); break; }
					case 92: { Utils::SetClantag("44-7____9"); break; }
					case 93: { Utils::SetClantag("4-7____93"); break; }
					case 94: { Utils::SetClantag("-7____937"); break; }
					case 95: { Utils::SetClantag("7____937-"); break; }
					case 96: { Utils::SetClantag("____937-7"); break; }
					case 97: { Utils::SetClantag("___937-7_"); break; }
					case 98: { Utils::SetClantag("__937-7__"); break; }
					case 99: { Utils::SetClantag("_937-7___"); break; }
					case 100: { Utils::SetClantag("937-7____"); break; }
					case 101: { Utils::SetClantag("37-7____9"); break; }
					case 102: { Utils::SetClantag("7-7____93"); break; }
					case 103: { Utils::SetClantag("-7____930"); break; }
					case 104: { Utils::SetClantag("7____930-"); break; }
					case 105: { Utils::SetClantag("____930-7"); break; }
					case 106: { Utils::SetClantag("___930-7_"); break; }
					case 107: { Utils::SetClantag("__930-7__"); break; }
					case 108: { Utils::SetClantag("_930-7___"); break; }
					case 109: { Utils::SetClantag("930-7____"); break; }
					case 110: { Utils::SetClantag("30-7____9"); break; }
					case 111: { Utils::SetClantag("0-7____92"); break; }
					case 112: { Utils::SetClantag("-7____923"); break; }
					case 113: { Utils::SetClantag("7____923-"); break; }
					case 114: { Utils::SetClantag("____923-7"); break; }
					case 115: { Utils::SetClantag("___923-7_"); break; }
					case 116: { Utils::SetClantag("__923-7__"); break; }
					case 117: { Utils::SetClantag("_923-7___"); break; }
					case 118: { Utils::SetClantag("923-7____"); break; }
					case 119: { Utils::SetClantag("23-7____9"); break; }
					case 120: { Utils::SetClantag("3-7____91"); break; }
					case 121: { Utils::SetClantag("-7____916"); break; }
					case 122: { Utils::SetClantag("7____916-"); break; }
					case 123: { Utils::SetClantag("____916-7"); break; }
					case 124: { Utils::SetClantag("___916-7_"); break; }
					case 125: { Utils::SetClantag("__916-7__"); break; }
					case 126: { Utils::SetClantag("_916-7___"); break; }
					case 127: { Utils::SetClantag("916-7____"); break; }
					case 128: { Utils::SetClantag("16-7____9"); break; }
					case 129: { Utils::SetClantag("6-7____90"); break; }
					case 130: { Utils::SetClantag("-7____909"); break; }
					case 131: { Utils::SetClantag("7____909-"); break; }
					case 132: { Utils::SetClantag("____909-7"); break; }
					case 133: { Utils::SetClantag("___909-7_"); break; }
					case 134: { Utils::SetClantag("__909-7__"); break; }
					case 136: { Utils::SetClantag("_909-7___"); break; }
					case 137: { Utils::SetClantag("909-7____"); break; }
					case 138: { Utils::SetClantag("09-7____9"); break; }
					case 139: { Utils::SetClantag("9-7____90"); break; }
					case 140: { Utils::SetClantag("-7____902"); break; }
					case 141: { Utils::SetClantag("7____902-"); break; }
					case 142: { Utils::SetClantag("____902-7"); break; }
					case 143: { Utils::SetClantag("___902-7_"); break; }
					case 144: { Utils::SetClantag("__902-7__"); break; }
					case 145: { Utils::SetClantag("_902-7___"); break; }
					case 146: { Utils::SetClantag("902-7____"); break; }
					case 147: { Utils::SetClantag("02-7____8"); break; }
					case 148: { Utils::SetClantag("2-7____89"); break; }
					case 149: { Utils::SetClantag("-7____895"); break; }
					case 150: { Utils::SetClantag("7____895-"); break; }
					case 151: { Utils::SetClantag("____895-7"); break; }
					case 152: { Utils::SetClantag("___895-7_"); break; }
					case 153: { Utils::SetClantag("__895-7__"); break; }
					case 154: { Utils::SetClantag("_895-7___"); break; }
					case 155: { Utils::SetClantag("895-7____"); break; }
					case 156: { Utils::SetClantag("95-7____8"); break; }
					case 157: { Utils::SetClantag("5-7____88"); break; }
					case 158: { Utils::SetClantag("-7____888"); break; }
					case 159: { Utils::SetClantag("7____888-"); break; }
					case 160: { Utils::SetClantag("____888-7"); break; }
					case 161: { Utils::SetClantag("___888-7_"); break; }
					case 162: { Utils::SetClantag("__888-7__"); break; }
					case 163: { Utils::SetClantag("_888-7___"); break; }
					case 164: { Utils::SetClantag("888-7____"); break; }
					case 165: { Utils::SetClantag("88-7____8"); break; }
					case 166: { Utils::SetClantag("8-7____88"); break; }
					case 167: { Utils::SetClantag("-7____881"); break; }
					case 168: { Utils::SetClantag("7____881-"); break; }
					case 169: { Utils::SetClantag("____881-7"); break; }
					case 170: { Utils::SetClantag("___881-7_"); break; }
					case 171: { Utils::SetClantag("__881-7__"); break; }
					case 172: { Utils::SetClantag("_881-7___"); break; }
					case 173: { Utils::SetClantag("881-7____"); break; }
					case 174: { Utils::SetClantag("81-7____8"); break; }
					case 175: { Utils::SetClantag("1-7____87"); break; }
					case 176: { Utils::SetClantag("-7____874"); break; }
					case 177: { Utils::SetClantag("7____874-"); break; }
					case 178: { Utils::SetClantag("____874-7"); break; }
					case 179: { Utils::SetClantag("___874-7_"); break; }
					case 180: { Utils::SetClantag("__874-7__"); break; }
					case 181: { Utils::SetClantag("_874-7___"); break; }
					case 182: { Utils::SetClantag("874-7____"); break; }
					case 183: { Utils::SetClantag("74-7____8"); break; }
					case 184: { Utils::SetClantag("4-7____86"); break; }
					case 185: { Utils::SetClantag("-7____867"); break; }
					case 186: { Utils::SetClantag("7____867-"); break; }
					case 187: { Utils::SetClantag("____867-7"); break; }
					case 188: { Utils::SetClantag("___867-7_"); break; }
					case 189: { Utils::SetClantag("__867-7__"); break; }
					case 190: { Utils::SetClantag("_867-7___"); break; }
					case 191: { Utils::SetClantag("867-7____"); break; }
					case 192: { Utils::SetClantag("67-7____8"); break; }
					case 193: { Utils::SetClantag("7-7____86"); break; }
					case 194: { Utils::SetClantag("-7____860"); break; }
					case 195: { Utils::SetClantag("7____860-"); break; }
					case 196: { Utils::SetClantag("____860-7"); break; }
					case 197: { Utils::SetClantag("___860-7_"); break; }
					case 198: { Utils::SetClantag("__860-7__"); break; }
					case 199: { Utils::SetClantag("_860-7___"); break; }
					case 200: { Utils::SetClantag("860-7____"); break; }
					case 201: { Utils::SetClantag("60-7____8"); break; }
					case 202: { Utils::SetClantag("0-7____85"); break; }
					case 203: { Utils::SetClantag("-7____853"); break; }
					case 204: { Utils::SetClantag("7____853-"); break; }
					case 205: { Utils::SetClantag("____853-7"); break; }
					case 206: { Utils::SetClantag("___853-7_"); break; }
					case 207: { Utils::SetClantag("__853-7__"); break; }
					case 208: { Utils::SetClantag("_853-7___"); break; }
					case 209: { Utils::SetClantag("853-7____"); break; }
					case 210: { Utils::SetClantag("53-7____8"); break; }
					case 211: { Utils::SetClantag("3-7____84"); break; }
					case 212: { Utils::SetClantag("-7____846"); break; }
					case 213: { Utils::SetClantag("7____846-"); break; }
					case 214: { Utils::SetClantag("____846-7"); break; }
					case 215: { Utils::SetClantag("___846-7_"); break; }
					case 216: { Utils::SetClantag("__846-7__"); break; }
					case 217: { Utils::SetClantag("_846-7___"); break; }
					case 218: { Utils::SetClantag("846-7____"); break; }
					case 219: { Utils::SetClantag("46-7____8"); break; }
					case 220: { Utils::SetClantag("6-7____83"); break; }
					case 221: { Utils::SetClantag("-7____839"); break; }
					case 222: { Utils::SetClantag("7____839-"); break; }
					case 223: { Utils::SetClantag("____839-7"); break; }
					case 224: { Utils::SetClantag("___839-7_"); break; }
					case 225: { Utils::SetClantag("__839_7__"); break; }
					case 226: { Utils::SetClantag("_839_7___"); break; }
					case 227: { Utils::SetClantag("839-7____"); break; }
					case 228: { Utils::SetClantag("39-7____8"); break; }
					case 229: { Utils::SetClantag("9-7____83"); break; }
					case 230: { Utils::SetClantag("-7____832"); break; }
					case 231: { Utils::SetClantag("7____832-"); break; }
					case 232: { Utils::SetClantag("____832-7"); break; }
					case 233: { Utils::SetClantag("___832-7_"); break; }
					case 234: { Utils::SetClantag("__832-7__"); break; }
					case 235: { Utils::SetClantag("_832-7___"); break; }
					default:;
					}
				}
			}

			prevtime = int(g_GlobalVars->curtime);
		}
	}
	else if (restore) {
		restore = false;
		Utils::SetClantag("");
	}

}
#define Square(x) ((x)*(x))
#define FastSqrt(x)	(sqrt)(x)

void MinWalk(CUserCmd* get_cmd, float get_speed) {

	if (!GetAsyncKeyState(g_Options.misc_minwalk_bind))
		return;

	if (g_LocalPlayer->m_vecVelocity().Length() > (g_LocalPlayer->m_hActiveWeapon()->GetCSWeaponData()->flMaxPlayerSpeed / (g_LocalPlayer->m_hActiveWeapon()->IsSniper() ? 3.65f : 2.f))) // https://youtu.be/ZgjYxBRuagA
	{
		get_cmd->buttons |= IN_WALK;
		get_cmd->forwardmove = 0;
		get_cmd->sidemove = 0;
		get_cmd->upmove = 0;
	}
}

void Fakelag(CUserCmd* cmd, bool& send_packet) {
	if (!g_Options.fakelag_enabled)
		return;
	
	if (g_Options.fakelag_unducking &&
		g_LocalPlayer->m_flDuckAmount() > 0.05f && g_LocalPlayer->m_flDuckAmount() < 0.95f) {
		send_packet = !(g_ClientState->chokedcommands < max_choke_ticks());
		return;
	}

	if (g_Options.fakelag_factor <= 0)
		return;

	int choke_factor = g_Options.misc_desync ? std::min(max_choke_ticks(), g_Options.fakelag_factor) : g_Options.fakelag_factor;

	auto LegitPeek = [choke_factor](CUserCmd* cmd, bool& send_packet) {
		static bool m_bIsPeeking = false;
		if (m_bIsPeeking) {
			send_packet = !(g_ClientState->chokedcommands < choke_factor);
			if (send_packet)
				m_bIsPeeking = false;
			return;
		}

		auto speed = g_LocalPlayer->m_vecVelocity().Length();
		if (speed <= 70.0f)
			return;

		auto collidable = g_LocalPlayer->GetCollideable();

		Vector min, max;
		min = collidable->OBBMins();
		max = collidable->OBBMaxs();

		min += g_LocalPlayer->m_vecOrigin();
		max += g_LocalPlayer->m_vecOrigin();

		Vector center = (min + max) * 0.5f;

		for (int i = 1; i <= g_GlobalVars->maxClients; ++i) {
			auto player = C_BasePlayer::GetPlayerByIndex(i);
			if (!player || !player->IsAlive() || player->IsDormant())
				continue;
			if (player == g_LocalPlayer || g_LocalPlayer->m_iTeamNum() == player->m_iTeamNum())
				continue;

			auto weapon = player->m_hActiveWeapon().Get();
			if (!weapon || weapon->m_iClip1() <= 0)
				continue;

			auto weapon_data = weapon->GetCSWeaponData();
			if (!weapon_data || weapon_data->iWeaponType <= WEAPONTYPE_KNIFE || weapon_data->iWeaponType >= WEAPONTYPE_C4)
				continue;

			auto eye_pos = player->GetEyePos();

			Vector direction;
			Math::AngleVectors(player->m_angEyeAngles(), direction);
			direction.NormalizeInPlace();

			Vector hit_point;
			bool hit = Math::IntersectionBoundingBox(eye_pos, direction, min, max, &hit_point);
			if (hit && eye_pos.DistTo(hit_point) <= weapon_data->flRange) {
				Ray_t ray;
				trace_t tr;
				CTraceFilterSkipEntity filter((C_BasePlayer*)player);
				ray.Init(eye_pos, hit_point);

				g_EngineTrace->TraceRay(ray, MASK_SHOT_HULL | CONTENTS_HITBOX, &filter, &tr);
				if (tr.contents & CONTENTS_WINDOW) { // skip windows
																							// at this moment, we dont care about local player
					filter.pSkip = tr.hit_entity;
					ray.Init(tr.endpos, hit_point);
					g_EngineTrace->TraceRay(ray, MASK_SHOT_HULL | CONTENTS_HITBOX, &filter, &tr);
				}

				if (tr.fraction == 1.0f || tr.hit_entity == g_LocalPlayer) {
					m_bIsPeeking = true;
					break;
				}
			}
		}
	};

	auto speed = g_LocalPlayer->m_vecVelocity().Length();
	bool standing = speed <= 1.0f;
	if (!g_Options.fakelag_standing && standing) {
		return;
	}

	if (!g_Options.fakelag_moving && !standing) {
		return;
	}

	enum FakelagMode {
		FakelagStatic = 0,
		FakelagSwitch,
		FakelagAdaptive,
		FakelagRandom,
		FakelagLegitPeek
	};

	float UnitsPerTick = 0.0f;

	int WishTicks = 0;
	int AdaptiveTicks = 2;
	static int LastRandomNumber = 5;
	static int randomSeed = 12345;

	switch (g_Options.fakelag_mode)
	{
	case FakelagSwitch:
		// apply same logic as static fakelag
		if (cmd->command_number % 30 > 15)
			break;
	case FakelagStatic:
		send_packet = !(g_ClientState->chokedcommands < choke_factor);
		break;
	case FakelagAdaptive:
		if (standing) {
			send_packet = !(g_ClientState->chokedcommands < choke_factor);
			break;
		}

		UnitsPerTick = g_LocalPlayer->m_vecVelocity().Length() * g_GlobalVars->interval_per_tick;
		while ((WishTicks * UnitsPerTick) <= 68.0f)
		{
			if (((AdaptiveTicks - 1) * UnitsPerTick) > 68.0f)
			{
				++WishTicks;
				break;
			}
			if ((AdaptiveTicks * UnitsPerTick) > 68.0f)
			{
				WishTicks += 2;
				break;
			}
			if (((AdaptiveTicks + 1) * UnitsPerTick) > 68.0f)
			{
				WishTicks += 3;
				break;
			}
			if (((AdaptiveTicks + 2) * UnitsPerTick) > 68.0f)
			{
				WishTicks += 4;
				break;
			}
			AdaptiveTicks += 5;
			WishTicks += 5;
			if (AdaptiveTicks > 16)
				break;
		}

		send_packet = !(g_ClientState->chokedcommands < WishTicks);
		break;
	case FakelagRandom:
		if (g_ClientState->chokedcommands < LastRandomNumber) {
			send_packet = false;
		}
		else {
			randomSeed = 0x41C64E6D * randomSeed + 12345;
			LastRandomNumber = (randomSeed / 0x10000 & 0x7FFFu) % choke_factor;
			send_packet = true;
		}
		break;
	case FakelagLegitPeek:
		LegitPeek(cmd, send_packet);
		break;
	}

	if (choke_factor < g_ClientState->chokedcommands)
		send_packet = true;

};

#include "../features/prediction.h"

void fakeduck(CUserCmd* pCmd, bool& bSendPacket) {
	int fakelag_limit = 14;
	int choked_goal = fakelag_limit / 2;

	

	if (g_LocalPlayer->m_fFlags() & FL_ONGROUND)
	{
		bSendPacket = g_ClientState->m_NetChannel->m_nChokedPackets >= fakelag_limit;

		if (g_ClientState->chokedcommands <= 7)
			pCmd->buttons &= ~IN_DUCK;
		else
			pCmd->buttons |= IN_DUCK;
	}
}

void nosmoke(){
	static bool set = true;

	static std::vector<const char*> vistasmoke_wireframe =
	{
		"particle/vistasmokev1/vistasmokev1_smokegrenade",
		"particle/vistasmokev1/vistasmokev1_fire",
		"particle/vistasmokev1/vistasmokev1_emods",
		"particle/vistasmokev1/vistasmokev1_emods_impactdust",
	};

	if (!g_Options.nosmoke)
	{
		if (set)
		{
			for (auto material_name : vistasmoke_wireframe)
			{
				IMaterial* mat = g_MatSystem->FindMaterial(material_name, TEXTURE_GROUP_OTHER);
				mat->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, false);
			}
			set = false;
		}
		return;
	}

	set = true;
	for (auto material_name : vistasmoke_wireframe)
	{
		IMaterial* mat = g_MatSystem->FindMaterial(material_name, TEXTURE_GROUP_OTHER);
		mat->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, true);
	}
	static auto shit = *(DWORD*)(Utils::PatternScan(GetModuleHandleA("client.dll"), "55 8B EC 83 EC 08 8B 15 ? ? ? ? 0F 57 C0") + 0x8);
	if(shit)
		if (g_Options.nosmoke)
			*(int*)(shit) = 0;
	

}

void CorrectMouse(CUserCmd* cmd) {
	static ConVar* m_yaw = m_yaw = g_CVar->FindVar("m_yaw");
	static ConVar* m_pitch = m_pitch = g_CVar->FindVar("m_pitch");
	static ConVar* sensitivity = sensitivity = g_CVar->FindVar("sensitivity");

	static QAngle m_angOldViewangles = g_ClientState->viewangles;

	float delta_x = std::remainderf(cmd->viewangles.pitch - m_angOldViewangles.pitch, 360.0f);
	float delta_y = std::remainderf(cmd->viewangles.yaw - m_angOldViewangles.yaw, 360.0f);

	if (delta_x != 0.0f) {
		float mouse_y = -((delta_x / m_pitch->GetFloat()) / sensitivity->GetFloat());
		short mousedy;
		if (mouse_y <= 32767.0f) {
			if (mouse_y >= -32768.0f) {
				if (mouse_y >= 1.0f || mouse_y < 0.0f) {
					if (mouse_y <= -1.0f || mouse_y > 0.0f)
						mousedy = static_cast<short>(mouse_y);
					else
						mousedy = -1;
				}
				else {
					mousedy = 1;
				}
			}
			else {
				mousedy = 0x8000u;
			}
		}
		else {
			mousedy = 0x7FFF;
		}

		cmd->mousedy = mousedy;
	}

	if (delta_y != 0.0f) {
		float mouse_x = -((delta_y / m_yaw->GetFloat()) / sensitivity->GetFloat());
		short mousedx;
		if (mouse_x <= 32767.0f) {
			if (mouse_x >= -32768.0f) {
				if (mouse_x >= 1.0f || mouse_x < 0.0f) {
					if (mouse_x <= -1.0f || mouse_x > 0.0f)
						mousedx = static_cast<short>(mouse_x);
					else
						mousedx = -1;
				}
				else {
					mousedx = 1;
				}
			}
			else {
				mousedx = 0x8000u;
			}
		}
		else {
			mousedx = 0x7FFF;
		}

		cmd->mousedx = mousedx;
	}
}
void NormalizeInOut(Vector& vIn, Vector& vOut)
{
	float flLen = vIn.Length();
	if (flLen == 0) {
		vOut.Init(0, 0, 1);
		return;
	}
	flLen = 1 / flLen;
	vOut.Init(vIn.x * flLen, vIn.y * flLen, vIn.z * flLen);
}
void Walkbot(QAngle& OrigAng, CUserCmd* cmd)
{

	bool walkbotBefore = false;

	QAngle viewangles;
	g_EngineClient->GetViewAngles(&viewangles);

	static int OldMouseX = OrigAng.yaw;
	int mousedx = OldMouseX - OrigAng.yaw;

	auto fDistanceToWall = [&](QAngle diff = QAngle(0, 0, 0))->float {
		auto tmpviewangles = viewangles + diff;
		trace_t tr;
		Ray_t ray;
		CTraceFilter filter;
		filter.pSkip = g_LocalPlayer;
		Vector begin = g_LocalPlayer->GetEyePos(), t, end;
		Math::AngleVectors(tmpviewangles, t);
		NormalizeInOut(t, end);
		end *= 8192.0f;
		end += begin;
		ray.Init(begin, end);
		g_EngineTrace->TraceRay(ray, 0x4600400B, &filter, &tr);
		return (begin - tr.endpos).Size();
	};

	static float old1, old2, old3;
	if (g_LocalPlayer->m_vecVelocity().Length() < 3)
	{
		viewangles.yaw += 2.0f;
	}
	float Distances = 100;
	if (fDistanceToWall() < Distances) // we are near to some wall
	{
		int turn = 5;
		float negativeDist = fDistanceToWall(QAngle(0, -1, 0)), positiveDist = fDistanceToWall(QAngle(0, 1, 0));
		if (abs(negativeDist - positiveDist) < 1.0f)
		{
			viewangles.yaw += turn;
		}
		else
		{
			viewangles.yaw += positiveDist < negativeDist ? -1 : 1;
		}
	}

	while (viewangles.yaw > 180.0f)
		viewangles.yaw -= 360.0f;
	while (viewangles.yaw < -180.0f)
		viewangles.yaw += 360.0f;

	g_EngineClient->SetViewAngles(&viewangles);

	if (!walkbotBefore)
	{
		cmd->forwardmove = 450.f;
		walkbotBefore = true;
	}

	else if (walkbotBefore)
	{
		walkbotBefore = false;
		cmd->forwardmove = 450.f;
	}
}

void Slowwalk(CUserCmd* cmd) {
	if (g_Options.misc_minwalk)
	{
		if (g_LocalPlayer->m_hActiveWeapon()) {
			if (g_LocalPlayer->m_hActiveWeapon()->m_Item().m_iItemDefinitionIndex() == WEAPON_SSG08)
				MinWalk(cmd, 70);
			else if (g_LocalPlayer->m_hActiveWeapon()->GetCSWeaponData()->iWeaponType == WEAPONTYPE_RIFLE || g_LocalPlayer->m_hActiveWeapon()->GetCSWeaponData()->iWeaponType == WEAPONTYPE_PISTOL)
				MinWalk(cmd, 67);
			else if (g_LocalPlayer->m_hActiveWeapon()->GetCSWeaponData()->iWeaponType == WEAPONTYPE_SUBMACHINEGUN)
				MinWalk(cmd, 76);
			else if (g_LocalPlayer->m_hActiveWeapon()->m_Item().m_iItemDefinitionIndex() == WEAPON_AWP)
				MinWalk(cmd, 30);
			else
				MinWalk(cmd, 36);
		}
	}
}
static DWORD delay = 0;

bool changeName(bool reconnect, const char* newName, float delay) noexcept
{
	static auto exploitInitialized{ false };

	static auto name{ g_CVar->FindVar("name") };

	if (reconnect) {
		exploitInitialized = false;
		return false;
	}

	if (!exploitInitialized && g_EngineClient->IsInGame()) {
		if (player_info_s playerInfo; g_EngineClient->GetPlayerInfo(g_LocalPlayer->EntIndex(), &playerInfo) && (!strcmp(playerInfo.szName, "?empty") || !strcmp(playerInfo.szName, "\n\xAD\xAD\xAD"))) {
			exploitInitialized = true;
		}
		else {
			name->m_fnChangeCallbacks.m_Size = 0;
			name->SetValue("\n\xAD\xAD\xAD");
			return false;
		}
	}

	static auto nextChangeTime{ 0.0f };
	if (nextChangeTime <= g_GlobalVars->realtime) {
		name->SetValue(newName);
		nextChangeTime = g_GlobalVars->realtime + delay;
		return true;
	}
	return false;
}
bool __stdcall Hooks::hkCreateMove(float input_sample_frametime, CUserCmd* cmd)
{
	static auto original = clientmode_hook.get_original<decltype(&hkCreateMove)>(index::CreateMove);
	clientmode_hook.hook_index(index::ClientModeCreateMove, hkCreateMove);
	original(input_sample_frametime, cmd);
	bool* send_packet = reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(_AddressOfReturnAddress()) + 0x14);
	auto oCreateMove = clientmode_hook.get_original< CreateMoveClientMode >(index::ClientModeCreateMove);
	bool result = oCreateMove(g_ClientMode, input_sample_frametime, cmd);

	uintptr_t* FPointer; __asm { MOV FPointer, EBP }
	byte* SendPacket = (byte*)(*FPointer - 0x1C);

	if (!cmd || !cmd->command_number)
		return result;
	if (!g_LocalPlayer)								return original;
		
	Globals::cmd = cmd;
	
	if (original)
		g_Prediction->SetLocalViewangles(Vector(cmd->viewangles.pitch, cmd->viewangles.yaw, cmd->viewangles.roll));

	if (g_Options.misc_bhop)						BunnyHop::OnCreateMove(cmd);
	if (g_Options.misc_autostrafer)					BunnyHop::AutoStrafe(cmd, cmd->viewangles);
	if (g_Options.misc_chat_spammer > 0) ChatSpammer();

	bool bSendPacket = *SendPacket;

	sendpacket = bSendPacket;
	
	static float SpawnTime = 0.0f;
	if (g_LocalPlayer->m_flSpawnTime() != SpawnTime) {
		g_AnimState.pBaseEntity = g_LocalPlayer;
		g_LocalPlayer->ResetAnimationState(&g_AnimState);
		SpawnTime = g_LocalPlayer->m_flSpawnTime();
	}

	Clantag();
	auto unpred_flags = g_LocalPlayer->m_fFlags();
	auto oldangles = cmd->viewangles;

	g_Options.dista = cmd->random_seed;

	//entities::fetch_targets(cmd);

	EnginePred::BeginPred(cmd);
	//c_prediction_system::Get().initial(g_LocalPlayer, cmd, 0);
	{
		AutoBlock(cmd);

		if (cmd->command_number % 2 == 1 && bSendPacket && !(g_Options.fakeduck && GetAsyncKeyState(g_Options.fakeduck_bind)) && g_Options.misc_desync)
			bSendPacket = false;

		if (g_Options.edgejump && GetAsyncKeyState(g_Options.edgejump_bind))
		{
			if ((unpred_flags & FL_ONGROUND) && !(g_LocalPlayer->m_fFlags() & FL_ONGROUND))
				cmd->buttons |= IN_JUMP;
		}
		QAngle angleold = cmd->viewangles;
		if (g_LocalPlayer->m_hActiveWeapon()) {
		
			g_Aimbot.OnMove(cmd);

			if (g_Options.slide)
				SlideWalk(cmd);

			if (g_Options.autoreload)
				AutoWeapons(cmd);


			g_Backtrack.OnMove(cmd);
			if (g_Options.trigenable || g_LocalPlayer->m_hActiveWeapon()->m_Item().m_iItemDefinitionIndex() == WEAPON_TASER)
				TriggerBot(cmd);

			if (g_Options.kbot)
				knifebot(cmd);


		}
	

		if (g_Options.misc_walkbot)
			Walkbot(oldangles, cmd);

		if (g_Options.misc_desync && g_ClientState->chokedcommands >= max_choke_ticks()) {
			bSendPacket = true;
			cmd->viewangles = g_ClientState->viewangles;
		}


		if (g_Options.misc_desync && std::fabsf(g_LocalPlayer->m_flSpawnTime() - g_GlobalVars->curtime) > 1.0f)
			Desync(cmd, bSendPacket);

		CorrectMouse(cmd);

		auto anim_state = g_LocalPlayer->GetPlayerAnimState();
		if (anim_state) {
			CCSGOPlayerAnimState anim_state_backup = *anim_state;
			*anim_state = g_AnimState;
			g_LocalPlayer->GetVAngles() = cmd->viewangles;
			g_LocalPlayer->UpdateClientSideAnimation();

			updatelby(anim_state);

			g_AnimState = *anim_state;
			*anim_state = anim_state_backup;
		}
		if (bSendPacket) {
			anglereal = g_AnimState.m_flGoalFeetYaw;
			if(anim_state)
				anglefake = anim_state->m_flGoalFeetYaw;
			vangle = cmd->viewangles;
		}


		Slowwalk(cmd);

		fix_movement(cmd, angleold);
	}
	EnginePred::EndPred();

	if (g_Options.fakeduck && GetAsyncKeyState(g_Options.fakeduck_bind) && !g_EngineClient->IsVoiceRecording())
		fakeduck(cmd, bSendPacket);

	if (g_Options.fakeduck && GetAsyncKeyState(g_Options.fakeduck_bind));
		cmd->buttons |= IN_BULLRUSH;

	if (!g_EngineClient->IsVoiceRecording() && !(g_Options.fakeduck && GetAsyncKeyState(g_Options.fakeduck_bind)))
		Fakelag(cmd, bSendPacket);

	nosmoke();

	if (g_LocalPlayer && InputSys::Get().IsKeyDown(VK_TAB) && g_Options.misc_rankreveal)
		Utils::RankRevealAll();

	if (g_Options.antiuntrusted)
	{
		Math::ClampAngles(cmd->viewangles);
	}
	
	//if ()
		//g_InputSystem->EnableInput();
	
	Math::FixAngles(cmd->viewangles);
	std::clamp(cmd->sidemove, -450.f, 450.f);
	std::clamp(cmd->forwardmove, -450.f, 450.f);
	std::clamp(cmd->upmove, -320.f, 320.f);
	Globals::bSendPacket = bSendPacket;
	*SendPacket = bSendPacket;

	return false;
}


void __fastcall Hooks::hkOverrideView(void* _this, int edx, CViewSetup* vsView)
{
	static auto override_view_o = clientmode_hook.get_original<decltype(&hkOverrideView)>(index::OverrideView);
	
	if (g_EngineClient->IsInGame() && g_LocalPlayer && vsView) {

		g_CVar->FindVar("weapon_debug_spread_show")->SetValue(g_Options.crosshair && !g_LocalPlayer->m_bIsScoped() ? 3 : 0);
		if (g_Options.nozoom)
		{

		}


		g_CVar->FindVar("zoom_sensitivity_ratio_mouse")->SetValue(float(!g_Options.nozoom));

		if (!Globals::got_w2s_matrix)
		{
			Globals::got_w2s_matrix = true;
			Globals::w2s_offset = (reinterpret_cast<DWORD>(&g_EngineClient->WorldToScreenMatrix()) + 0x40);
		}

		static auto viewmodel_fov = g_CVar->FindVar("viewmodel_fov");

		viewmodel_fov->m_fnChangeCallbacks.m_Size = 0;
		viewmodel_fov->SetValue(g_Options.misc_viewmodel_fov);

		Visuals::Get().ThirdPerson();
		if (!g_LocalPlayer->m_bIsScoped())
			vsView->fov = g_Options.misc_fov;
		else if(g_LocalPlayer->m_bIsScoped() && g_Options.nozoom && g_LocalPlayer->m_hActiveWeapon() &&
			g_LocalPlayer->m_hActiveWeapon()->m_iItemDefinitionIndex() != WEAPON_SG556 &&
			g_LocalPlayer->m_hActiveWeapon()->m_iItemDefinitionIndex() != WEAPON_AUG)
			vsView->fov = g_Options.misc_fov;

		if (g_Options.fakeduck && GetAsyncKeyState(g_Options.fakeduck_bind) && g_LocalPlayer->IsAlive() && g_LocalPlayer->m_fFlags() & FL_ONGROUND)
			vsView->origin.z = g_LocalPlayer->m_vecOrigin().z + 64; 

		if (g_Options.esp_grenade_prediction && g_LocalPlayer->m_hActiveWeapon())
			GrenadePrediction::Get().View(vsView);

	override_view_o(g_ClientMode, edx,vsView);
	}
}

int __fastcall Hooks::hkDoPostScreenEffects(void* _this, int edx, int a1)
{
	static auto do_pose_effects_o = clientmode_hook.get_original<decltype(&hkDoPostScreenEffects)>(index::DoPostScreenSpaceEffects);

	

	return do_pose_effects_o(g_ClientMode, edx, a1);
}
