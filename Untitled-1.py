import re
def is_pal(s: str) -> bool:
    cs = re.sub(r'[^a-z0-9]', '', s.lower())
    return cs == cs[::-1]



if __name__ == "__main__":