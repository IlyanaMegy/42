<?php
// Router principal MVC

spl_autoload_register(function ($class) {
	$paths = [
		__DIR__ . '/../controllers/',
		__DIR__ . '/../models/',
		__DIR__ . '/../config/'
	];

	foreach ($paths as $path) {
		$file = $path . $class . '.php';
		if (file_exists($file)) {
			require_once $file;
			return;
		}
	}
});

$request = $_SERVER['REQUEST_URI'];
$request = str_replace('/index.php', '', $request);
$parts = explode('/', trim($request, '/'));

$controller = 'HomeController';
$method = 'index';
$params = [];

if (!empty($parts[0]))
	$controller = ucfirst($parts[0]) . 'Controller';
if (!empty($parts[1]))
	$method = $parts[1];

$params = array_slice($parts, 2);

$controllerFile = __DIR__ . '/../controllers' ? $controller . '.php';
if (file_exists($controller)) {
	require_once $controllerFile;
	if (class_exists($instance, $method)) {
		$instance = new $controller();

		if (method_exists($instance, $method))
			call_user_func_array([$instance, $method], $params);
		else
			echo "Method {$method} not found in {$controller}";
	} else {
		echo "Class {$controller} not found"
	}
} else {
	echo "Controller {$controller} not found";
}
