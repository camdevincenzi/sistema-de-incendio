# Sistema de incendios
Sistema de incendios con Arduino R1 simulado en Tinkercad

[![portada.png](https://i.postimg.cc/76GRHMmk/portada.png)](https://postimg.cc/njx2TmyR)

Su función es detectar si se está produciendo un incendio según la estación del año

Link del proyecto: https://www.tinkercad.com/things/1kScscwGUMy?sharecode=KO48qNIrqH1VtkeUPGx3m32a7YJmmU9qWqaskQPCuC8

### Componentes
1. Arduino R1
2. Sensor de temperatura: establece la temperatura entre los -40° y 125°
3. LCD 16x2: Muestra la temperatura actual y la estación del año si es que se elige una
4. Control remoto por IR: Configurado para seleccionar una estación del año
5. Servo: Comienza a girar simulando ser un aspersor una vez que se detecta un incendio
6. Luces led: Titilan o se encienden según la temperatura y la estación seleccionadas
7. Resistencias

[![vistaprevia.png](https://i.postimg.cc/SsCG1ZgJ/vistaprevia.png)](https://postimg.cc/ZBY3CLtS)

### Funcionamiento
El programa comienza mostrando en el LCD 16x2 la temperatura ambiente

Con el control remoto IR establecemos una estación del año:

1. Otoño 
2. Invierno
3. Primavera
4. Verano

Una vez seleccionada la estación se podrá detectar un incendio

### Condiciones para que se detecte un incendio:
1. Temperatura superior a los 50° en Otoño
2. Temperatura superior a los 40° en Invierno
3. Temperatura superior a los 60° en Primavera
4. Temperatura superior a los 70° en Verano

Mientras el clima esté dentro de los valores normales, titilará un led azul cada 1 segundo

[![muestra1.jpg](https://i.postimg.cc/6q0tx5FM/muestra1.jpg)](https://postimg.cc/5Q6Zw14z)

Si estamos cerca de la detección de un incendio (10° o menos), titilará un led rojo cada 1 segundo

[![muestra2.jpg](https://i.postimg.cc/K83wn8QC/muestra2.jpg)](https://postimg.cc/pmxsvxwB)

Si se detecta un incendio, el led rojo permanecerá encendido, se activará el servo y se mostrará en el LCD un mensaje de alerta

[![muestra3.jpg](https://i.postimg.cc/65M4d9TV/muestra3.jpg)](https://postimg.cc/4mh3GR6n)

Vista previa del simulador:

[![videomuestra.gif](https://i.postimg.cc/3NtNw5Ky/videomuestra.gif)](https://postimg.cc/WqJT9yqj)

