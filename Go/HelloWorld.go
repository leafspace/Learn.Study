package main

import "./PublicPackage"
import "fmt"

func FuncSum(a int, b int) int {
	return a + b
}

func main() {
	fmt.Println("Hello World !")

	var result int
	result = FuncSum(1, 2)

	var result2 int = FuncSum(result, 1)

	fmt.Println(result2)

	str := "Auto Define String"

	fmt.Println(str);
}