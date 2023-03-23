from decimal import Decimal

t = int(input())
for _ in range(t):
    num_chips = int(input())
    root = int(Decimal(num_chips).sqrt())
    if root * root == num_chips:
        print(root - 1)
    else:
        print(root)
