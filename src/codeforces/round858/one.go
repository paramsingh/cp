package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scanf("%d\n", &t)
	for t > 0 {
		t--
		var a, b, c, d int
		fmt.Scanf("%d %d %d %d\n", &a, &b, &c, &d)
		if b > d {
			fmt.Println("-1")
			continue
		}
		diff := d - b
		a += diff
		b = d

		if a < c {
			fmt.Println("-1")
			continue
		} else {
			fmt.Printf("%d\n", diff+(a-c))
			continue
		}
	}
}
