# Buffer Overflow Exploitation under NX and ASLR Protections

This work practically adapts Krahmer's borrowed code chunks technique <sup>[1]</sup> for modern x86-64 systems, building a working ROP chain exploit that bypasses NX using return-to-libc attacks.

Additionally, it explains how ASLR can be bypassed using techniques such as dl-resolve, based on Wojtczuk’s return-into-lib(c) work <sup>[2]</sup>.

## References

[1] Sebastian Krahmer. *x86-64 Buffer Overflow Exploits and the Borrowed Code Chunks Exploitation Technique*, 2005.  

[2] Rafal Wojtczuk. *The Advanced Return-into-lib(c) Exploits: PaX Case Study*. Phrack Magazine, Volume 0x0b, Issue 0x3a, Phile# 0x04 of 0x0e, 2001.
