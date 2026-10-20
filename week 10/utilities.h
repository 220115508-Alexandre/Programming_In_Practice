#ifndef UTILITIES_H
#define UTILITIES_H

void pauseScreen(void);
int  readInt(const char *prompt);
float readFloat(const char *prompt);
void clearInputBuffer(void);
void readString(const char *prompt, char *buf, int size);

#endif
