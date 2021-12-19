use std::io;


fn main() {
    let mut t = String::new();
    io::stdin().read_line(&mut t).expect("input error");
    let mut t: i32 = t.trim().parse().expect("input error");
    while t > 0 {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("input error");
        if input.matches('N').count() == 1 {
            println!("NO");
        } else {
            println!("YES");
        }
        t -= 1;
    }
}
