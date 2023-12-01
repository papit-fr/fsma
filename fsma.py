import ctypes

lib = ctypes.CDLL("./libfsma.so")
fsma = lib.fsma
fsma.argtypes = [ctypes.c_ulonglong, ctypes.c_ulonglong, ctypes.c_ulonglong]
fsma.restype = ctypes.c_ulonglong

if __name__ == "__main__":
    # Use test function
    from utils import test_function

    test_function(fsma)
