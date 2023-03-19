/*
	A template for Go on codeforces.com
	Author: algo.tensai.me
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"reflect"
	"strconv"
	"strings"
)

func setVal(answer map[int]map[int]int64, i int, j int, val int64) {
	mp, ok := answer[i]
	if !ok {
		mp = make(map[int]int64)
		answer[i] = mp
	}
	mp[j] = val
}

func getVal(answers map[int]map[int]int64, i int, j int) int64 {
	mp, ok := answers[i]
	if !ok {
		return -1
	}
	val, ok := mp[j]
	if !ok {
		return -1
	}
	return val
}

func getAnswerFromMap(answers map[int]map[int]int64, node1 int, node2 int) int64 {
	val := getVal(answers, node1, node2)
	if val != -1 {
		return val
	}
	val = getVal(answers, node2, node1)
	if val != -1 {
		return val
	}
	return -1
}
func main() {
	line := readInts()
	_, q := line[0], line[1]
	a := readLongs()
	a = append([]int64{0}, a...)
	p := readInts()
	p = append([]int{0, 0}, p...)

	answers := make(map[int]map[int]int64)
	for i := 0; i < q; i++ {
		line = readInts()
		node1, node2 := line[0], line[1]
		sol := getAnswerFromMap(answers, node1, node2)
		if sol != -1 {
			writeLine(sol)
			continue
		}
		answer := make([]int64, 0, 10)
		node1s := make([]int, 0, 10)
		node2s := make([]int, 0, 10)

		sum := int64(0)
		for node1 != 0 && node2 != 0 {
			sol := getAnswerFromMap(answers, node1, node2)
			if sol != -1 {
				sum = sol
				break
			}
			node1s = append(node1s, node1)
			node2s = append(node2s, node2)
			answer = append(answer, a[node1]*a[node2])
			node1 = p[node1]
			node2 = p[node2]
		}
		for j := len(node1s) - 1; j >= 0; j-- {
			node1, node2 = node1s[j], node2s[j]
			sum += answer[j]
			setVal(answers, node1, node2, sum)
		}
		answer = nil
		node1s = nil
		node2s = nil
		writeLine(sum)
	}
}

/* ~~~~~~~~~~ */
/* ~~~~~~~~~~ */
/* ~~~~~~~~~~ */

var in = bufio.NewReader(os.Stdin)

type float = float32
type double = float64
type long = int64
type ulong = uint64

func typeOf(arg interface{}) string {
	switch reflect.TypeOf(arg).Kind() {
	case reflect.Int:
		return "int"
	case reflect.Int8:
		return "int8"
	case reflect.Int16:
		return "int16"
	case reflect.Int32:
		return "int32"
	case reflect.Int64:
		return "int64"
	case reflect.Uint:
		return "uint"
	case reflect.Uint8:
		return "uint8"
	case reflect.Uint16:
		return "uint16"
	case reflect.Uint32:
		return "uint32"
	case reflect.Uint64:
		return "uint64"
	case reflect.Float32:
		return "float32"
	case reflect.Float64:
		return "float64"
	case reflect.Complex64:
		return "complex64"
	case reflect.Complex128:
		return "complex128"
	case reflect.Bool:
		return "bool"
	case reflect.String:
		return "string"
	case reflect.Chan:
		return "chan"
	case reflect.Ptr:
		return "ptr"
	case reflect.Uintptr:
		return "uintptr"
	case reflect.UnsafePointer:
		return "unsafeptr"
	case reflect.Interface:
		return "interface"
	case reflect.Array:
		return "array"
	case reflect.Slice:
		return "slice"
	case reflect.Map:
		return "map"
	case reflect.Struct:
		return "struct"
	case reflect.Func:
		return "func"
	case reflect.Invalid:
		return "invalid"
	default:
		return "nil"
	}
}

/* ~~~~~~~~~~ */

func _scln() string {
	ln, _ := in.ReadString('\n')
	return strings.Trim(ln, " \r\n")
}
func _sc(s []string) string {
	if len(s) == 0 {
		return _scln()
	}
	return s[0]
}

func readLine() string              { return _scln() }
func readString() string            { return _scln() }
func readStrings() []string         { return strings.Split(_scln(), " ") }
func readBool(s ...string) bool     { t, _ := strconv.ParseBool(_sc(s)); return t }
func readByte(s ...string) byte     { t, _ := strconv.ParseUint(_sc(s), 10, 8); return byte(t) }
func readDouble(s ...string) double { t, _ := strconv.ParseFloat(_sc(s), 64); return t }
func readFloat(s ...string) float   { t, _ := strconv.ParseFloat(_sc(s), 32); return float32(t) }
func readInt(s ...string) int       { t, _ := strconv.Atoi(_sc(s)); return t }
func readLong(s ...string) long     { t, _ := strconv.ParseInt(_sc(s), 10, 64); return t }
func readULong(s ...string) ulong   { t, _ := strconv.ParseUint(_sc(s), 10, 64); return t }

/* ~~~~~~~~~~ */

// Too much overhead with universal method using interface{}, wait for the generics,
// but for now — just don't look at the redundancy of the code after that commentary :)

func readBools() []bool {
	strs := readStrings()
	arr := make([]bool, len(strs))
	for i, s := range strs {
		arr[i] = readBool(s)
	}
	return arr
}
func readBytes() []byte {
	strs := readStrings()
	arr := make([]byte, len(strs))
	for i, s := range strs {
		arr[i] = readByte(s)
	}
	return arr
}
func readDoubles() []double {
	strs := readStrings()
	arr := make([]double, len(strs))
	for i, s := range strs {
		arr[i] = readDouble(s)
	}
	return arr
}
func readFloats() []float {
	strs := readStrings()
	arr := make([]float, len(strs))
	for i, s := range strs {
		arr[i] = readFloat(s)
	}
	return arr
}
func readInts() []int {
	strs := readStrings()
	arr := make([]int, len(strs))
	for i, s := range strs {
		arr[i] = readInt(s)
	}
	return arr
}
func readLongs() []long {
	strs := readStrings()
	arr := make([]long, len(strs))
	for i, s := range strs {
		arr[i] = readLong(s)
	}
	return arr
}
func readULongs() []ulong {
	strs := readStrings()
	arr := make([]ulong, len(strs))
	for i, s := range strs {
		arr[i] = readULong(s)
	}
	return arr
}

/* ~~~~~~~~~~ */

func write(arg ...interface{})                 { fmt.Print(arg...) }
func writeLine(arg ...interface{})             { fmt.Println(arg...) }
func writeFormat(f string, arg ...interface{}) { fmt.Printf(f, arg...) }
