//
// Created by konrad on 29.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

namespace memorychunk {
    class MemoryChunk {
        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
