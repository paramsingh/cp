use std::io;
use std::cmp::max;

fn get_line() -> Vec<i64> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("could not read line");
    return input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect::<Vec<_>>();
}

fn main() {
    let mut t = get_line()[0];
    while t > 0 {
        t -= 1;
        let mut line = get_line();
        let (w, h) = (line[0], line[1]);
        line = get_line();
        let (minx1, maxx1) = (line[1], line[line[0] as usize]);
        line = get_line();
        let (minx2, maxx2) = (line[1], line[line[0] as usize]);
        let basex = max(maxx1 - minx1, maxx2 - minx2);

        line = get_line();
        let (miny1, maxy1) = (line[1], line[line[0] as usize]);
        line = get_line();
        let (miny2, maxy2) = (line[1], line[line[0] as usize]);
        let basey = max(maxy1 - miny1, maxy2 - miny2);


        let ans = max(basex * h, basey * w);
        println!("{}", ans);
    }
}
