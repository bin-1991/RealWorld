import sys, os, shutil, subprocess
import getopt, platform
import hashlib

rdir = os.getcwd()

def hash_file(f):
    file = open(f, "r", errors='ignore', encoding='utf-8')
    txt = file.read()
    file.close()
    sha = hashlib.sha256()
    sha.update(txt.encode('utf-8'))
    return sha.hexdigest()

def update_hash(f, h):
    name = os.path.split(f)[1]
    a = []
    try:
        cache = open("./ui/cache", "r", errors='ignore', encoding="utf-8")
        txt = cache.read()
        cache.close()
        a = txt.splitlines()
    except:
        print("create cache file.")

    for l in a:
        b = l.split(',')
        if b[0] == name:
            if h == b[1]:
                return 0    # this is new
            a.remove(l)
            break

    #add new hash
    l = f + ',' + h
    a.append(l)
    cache = open('./ui/cache', "w", errors='ignore', encoding='utf-8')
    txt = '\n'.join(a)
    cache.write(txt)
    cache.close()
    return 1


def update_file(cmd, src):
    h = hash_file(src)
    if update_hash(src, h) == 0:
        return 0

    print(cmd)
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
    o, e = proc.communicate()
    if proc.returncode != 0:
        #print("generate file error (%d).\n\n" % proc.returncode)
        raise RuntimeError("generate file error (%d).\n\n" % proc.returncode)
        return proc.returncode

def gen_mic():
    print("generating uic file ...")
    uifiles = [i for i in os.listdir('.') if os.path.isfile(i) and os.path.splitext(i)[1] == '.ui']
    for f in uifiles:
        cmd = "uic " + f + " -o ./ui/ui_" + os.path.splitext(f)[0] + ".h"
        update_file(cmd, f)
    print('generate uic success.\n')
    return 0

def gen_qrc():
    print("generating rcc file ...")
    uifiles = [i for i in os.listdir('.') if os.path.isfile(i) and os.path.splitext(i)[1] == '.qrc']
    for f in uifiles:
        cmd = "rcc -no-compress " + f + " -o ./ui/qrc_" + os.path.splitext(f)[0] + ".cpp"
        update_file(cmd, f)
    print('generate rcc success.\n')
    return 0

def gen_moc():
    print("generating moc file ...")
    moc = open("./ui/virboxprotector_automoc.cpp", "w", encoding="utf8")
    uifiles = [i for i in os.listdir('.') if os.path.isfile(i) and os.path.splitext(i)[1] == '.h']
    for f in uifiles:
        file = open(f, 'r', errors='ignore', encoding='utf-8')
        txt = file.read()
        file.close()
        if txt.find("Q_OBJECT") >= 0:
            cmd = "moc " + f + " -o ./ui/moc_" + os.path.splitext(f)[0] + ".cpp"
            update_file(cmd, f)
            moc.write("#include \"moc_" + os.path.splitext(f)[0] + ".cpp\"\n")

    moc.close()
    print('generate moc success.\n')
    return 0

def main(argv):
    try:
        gen_moc()
        gen_qrc()
        gen_mic()

    except Exception as e:
        print(e)
    exit(0)


if __name__ == "__main__":
    pwd = os.getcwd()

    py_path = os.path.dirname(__file__)
    os.chdir(py_path)

    main(sys.argv[1:])

    os.chdir(pwd)
