# Timer

Implementa un thread que ejecuta un callback cada intervalo de tiempo

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/Timer.git .
```

Esto creara el directorio Timer de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la ultima vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la ultima versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la última versión siguiendo los pasos de Selección de versión

## Uso

El uso es sencillo, basta con instanciar un objeto de la clase Timer y configurar el intervalo y las funciones callbacks que se ejecutaran en cada estado. Principalmente en el estado Tick.

``` c++
Timer timer;
...
timer.SetInterval(1000);
timer.OnTick( miFuncion );
```

Luego se inicia el parpadeo ejecutando el metodo **Start()**

``` c++
timer.Start();
```

Es obligatorio que se realice una llamada al metodo **Loop()** dentro del bucle infinito del procesador para que Timer sea capaz de calcular los intervalos de tiempos y ejecutar la función cargada en OnTick().

``` c++
void loop(){
    timer.Loop();
}
```

## Links

- [Cambios de version](CHANGELOG.md)
- [Repositorio](https://gitlab.com/arduinolibraries/Flicker/-/tree/master)