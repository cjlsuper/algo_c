//
// Created by 崔继霖 on 2020/10/22.
//

/**
   Man is distinguished, not only by his reason, but by this singular passion from other animals,
   which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable
   generation of knowledge, exceeds the short vehemence of any carnal pleasure.

   base64:
    TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz
    IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg
    dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu
    dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo
    ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>

int b64_encoded_size(int inlen);

char *b64_encode(const unsigned char *in, int in_len, int out_len);

int b64_decoded_size(const char *in);

int b64_decode(const char *in, char *out, int out_len);

int b64_isvalid_char(char c);


static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

static const unsigned char b64chars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


static char *test_decode = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz\n"
                           "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg\n"
                           "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu\n"
                           "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo\n"
                           "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

int b64_encoded_size(int inlen) {

    int ret;
    ret = inlen;
    if (inlen % 3 != 0) {
        ret += 3 - (inlen % 3);
    }
    ret /= 3;
    ret *= 4;

    return ret;
}

char *b64_encode(const unsigned char *in, int in_len, int len) {
    char *out;
    int elen;
    int i;
    int j;

    if (in == NULL || len == 0)
        return NULL;

    elen = in_len;
    out = static_cast<char *>(malloc(elen + 1));
    out[elen] = '\0';
    int sl = in_len / 3 * 3;

    for (i = 0, j = 0; i < sl;) {
        int bits = (in[i++] & 0xff) << 16 |
                   (in[i++] & 0xff) << 8 |
                   (in[i++] & 0xff);
        out[j++] = b64chars[(bits >> 18) & 0x3f];
        out[j++] = b64chars[(bits >> 12) & 0x3f];
        out[j++] = b64chars[(bits >> 6) & 0x3f];
        out[j++] = b64chars[bits & 0x3f];
    }

    if (i < in_len) {
        int b = in[i++] & 0xff;
        out[j++] = b64chars[b >> 2];
        if (i == in_len) {
            out[j++] = b64chars[b << 4 & 0x3f];
            out[j++] = '=';
            out[j++] = '=';
        } else {
            out[j++] = b64chars[b << 4 & 0x3f | (in[i] & 0xff) >> 4];
            out[j++] = b64chars[((in[i++] & 0xff) << 2) & 0x3f];
            out[j++] = '=';
        }
    }

    return out;
}

int b64_decode(const char *in, char *out, int out_len) {

    if (in == NULL || out == NULL)
        return 0;
    int len;
    len = strlen(in);
    if (out_len < b64_decoded_size(in) || len % 4 != 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!b64_isvalid_char(in[i])) {
            return 0;
        }
    }
    out[out_len] = '\0';

    int from_base[256];
    //使用memset方法
    memset(from_base, -1, sizeof(int) * 256);
    for (int m = 0; m < sizeof(encoding_table); ++m) {
        from_base[encoding_table[m]] = m;
    }
    from_base['='] = -2;

    int dp = 0;
    int sss = 0;
    int bits = 0;
    int shift_to = 18;       // pos of first byte of 4-byte atom
    //YWJj
    while (sss < len) {
        int b = in[sss++] & 0xff;
        if ((b = from_base[b]) < 0) {
            if (b == -2) {
                if (shift_to == 6 && (sss == len || in[sss++] != '=') || shift_to == 18) {
                    printf("Input byte array has wrong 4-byte ending unit");
                    exit(0);
                } else {
                    break;
                }
            } else {
                printf("Illegal base64 character");
                exit(0);
            }
        }

        bits |= (b << shift_to);
        shift_to -= 6;
        if (shift_to < 0) {
            out[dp++] = (bits >> 16);
            out[dp++] = (bits >> 8);
            out[dp++] = (bits);
            shift_to = 18;
            bits = 0;
        }
    }

    if (shift_to == 6) {
        out[dp++] = bits >> 16;
    } else if (shift_to == 0) {
        out[dp++] = (bits >> 16);
        out[dp++] = (bits >> 8);
    } else if (shift_to == 12) {
        // dangling single "x", incorrectly encoded.
        return 0;
    }
    while (sss < len) {
        printf("Input byte array has incorrect ending byte at ");
    }
    return 1;
}

int b64_isvalid_char(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c == '+' || c == '/' || c == '=')
        return 1;
    return 0;
}

int b64_decoded_size(const char *in) {
    int len;
    int ret;
    int i;
    if (in == NULL)
        return 0;
    len = strlen(in);
    ret = len / 4 * 3;
    for (i = len; i-- > 0;) {
        if (in[i] == '=') {
            ret--;
        } else {
            break;
        }
    }
    return ret;
}

int main() {
    // encode
    static const char *source = "a";
    int len = b64_encoded_size(strlen(source));
    char *p = b64_encode((const unsigned char *) source, strlen(source), len);
    printf("encode:%s\n", p);

    // decode
    //YWJjZGVmZzEyMw==
    int len_decode = b64_decoded_size(p);
    char *out = static_cast<char *>(malloc(len_decode + 1));
    b64_decode((const char *) p, out, len_decode);
    printf("decode:%s\n", out);

    return 0;
}

