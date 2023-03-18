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

func main() {
	t := readInt()
	for t > 0 {
		t--
		n := readInt()
		a := readInts()
		zeros := 0
		greaterThanOne := 0
		ones := 0

		for i := 0; i < n; i++ {
			if a[i] == 0 {
				zeros++
			}
			if a[i] > 1 {
				greaterThanOne++
			}
			if a[i] == 1 {
				ones++
			}
		}

		if zeros == n {
			writeLine(1)
			continue
		}
		if zeros == 1 || zeros == 0 {
			writeLine(0)
			continue
		}
		nonZeros := n - zeros
		if zeros <= nonZeros+1 {
			writeLine(0)
			continue
		}

		if greaterThanOne > 0 {
			writeLine(1)
			continue
		}

		if ones > 0 {
			writeLine(2)
			continue
		}

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
