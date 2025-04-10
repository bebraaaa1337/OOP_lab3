## Notifications
Лабораторная 3. Задача 2
Вам нужно написать классы SmsNotifier и EmailNotifier, унаследованные от базового класса NotifierBase и переопределяющие функцию Notify, чтобы приведённый код в ```test_basic.cpp``` заработал. Функция Notify в этих классах должна вызывать данные вам функции SendSms или SendEmail. 

## Запуск Сборки и тестов через терминал

```bash
cmake -B build # Генерируем файлы сборки
cmake --build build # Собираем
cd build # Заходим в дерикторию сборки
ctest --output-on-failure # Запуск тестов
```