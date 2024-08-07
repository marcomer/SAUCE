#ifndef SAUCE_TEST_RES_HEADER_INCLUDED
#define SAUCE_TEST_RES_HEADER_INCLUDED
#include <stdio.h>
#include "SauceTool.h"

#pragma warning(disable:4113)

// Basic files for reading. These files should not be changed

// TestFile1 -> ANSI file with SAUCE record and comment
#define SAUCE_TESTFILE1_PATH    "expect/TestFile1.ans"

// TestFile2 -> File only containing a SAUCE record
#define SAUCE_TESTFILE2_PATH    "expect/TestFile2.ans"

// TestFile3 -> File containing original file contents and a SAUCE record (w/ no comment)
#define SAUCE_TESTFILE3_PATH    "expect/TestFile3.ans"

// No Sauce File -> File does not contain any SAUCE info
#define SAUCE_NOSAUCE_PATH      "expect/NoSauce.ans"

// ShortFile -> File under 128 bytes
#define SAUCE_SHORTFILE_PATH    "expect/ShortFile.ans"

// SauceButNoEOF -> TestFile1 with a missing EOF character
#define SAUCE_SAUCEBUTNOEOF_PATH  "expect/SauceButNoEOF.ans"

// CommentButNoRecord -> TestFile1 without a SAUCE record
#define SAUCE_COMMENTBUTNORECORD_PATH   "expect/CommentButNoRecord.ans"

// InvalidComment -> Long file with an incorrect Comments field
#define SAUCE_INVALIDCOMMENT_PATH       "expect/InvalidComment.ans"

// LongNoSauce -> A CMakeLists.txt file with no SAUCE info
#define SAUCE_LONGNOSAUCE_PATH          "expect/LongNoSauce.ans"

// OnlyRecord -> Record from TestFile2.ans but with no EOF character
#define SAUCE_ONLYRECORD_PATH           "expect/OnlyRecord.ans"

// NoSauceWithEOF.ans -> Contains normal file contents with an ending EOF character
#define SAUCE_NOSAUCEWITHEOF_PATH       "expect/NoSauceWithEOF.ans"

// EmptyFile.ans -> A completely empty file
#define SAUCE_EMPTYFILE_PATH            "expect/EmptyFile.ans"


// Expected write file results. These files should not be changed

// Result of writing to an empty file
#define SAUCE_WRITETOEMPTY_PATH   "expect/write/WriteToEmptyExpect.ans"

// Result of replacing TestFile1's SAUCE record
#define SAUCE_REPLACE_PATH        "expect/write/ReplaceExpect.ans"

// Result of appending to a file
#define SAUCE_APPEND_PATH         "expect/write/AppendExpect.ans"

// Result of appending to NoSauceWithEOF.ans
#define SAUCE_APPENDWITHEOF_PATH  "expect/write/AppendWithEOFExpect.ans"

// File to contain the actual results of a test write
#define SAUCE_WRITE_ACTUAL_PATH   "actual/write_actual.ans"


// Expected remove file results. These files should not be changed

// Result of removing a SAUCE record from TestFile3.ans
#define SAUCE_REMOVE_ONLY_RECORD_PATH "expect/remove/RemoveOnlyRecord.ans"

// Result of removing a SAUCE record and CommentBlock from TestFile1.ans
#define SAUCE_REMOVE_RECORD_AND_COMMENT_PATH  "expect/remove/RemoveBoth.ans"

// Result of removing a SAUCE record from InvalidComment.ans
#define SAUCE_REMOVE_INVALID_COMMENT_PATH     "expect/remove/RemoveInvalidComment.ans"

// File to contain the actual results of a test remove
#define SAUCE_REMOVE_ACTUAL_PATH  "actual/remove_actual.ans"


// Expected comment write file results. These files should not be changed.

// File to contain the acutal results of a test comment write
#define SAUCE_COMMENT_WRITE_ACTUAL_PATH     "actual/comment_write_actual.ans"

// AddCommentToRecord -> Contains the result of adding shortComment to TestFile2.ans
#define SAUCE_ADDCOMMENTTORECORD_PATH       "expect/comment_write/AddCommentToRecord.ans"

// ReplaceExistingComment -> Contains the result of replacing TestFile1's comment with longComment
#define SAUCE_REPLACEEXISTINGCOMMENT_PATH   "expect/comment_write/ReplaceExistingComment.ans"

// AddCommentAndEOFToRecord -> Contains the result of adding shortComment and an EOF to OnlyRecord.ans
#define SAUCE_ADDCOMMENTANDEOFTORECORD_PATH   "expect/comment_write/AddCommentAndEOFToRecord.ans"

// ReplaceCommentAndAddEOF -> Contains the result of replacing SauceButNoEOF's comment with shortComment and adding EOF
#define SAUCE_REPLACECOMMENTANDADDEOF_PATH    "expect/comment_write/ReplaceCommentAndAddEOF.ans"

// SameCommentLength -> Contains the result of replacing TestFile1's comment with shortComment but padded to 2 lines
#define SAUCE_SAMECOMMENTLENGTH_PATH          "expect/comment_write/SameCommentLength.ans"


// Expected comment remove file results. These files should not be changed

// File to contain the actual result of a test comment remove
#define SAUCE_COMMENT_REMOVE_ACTUAL_PATH    "actual/comment_remove_actual.ans"

// RemoveComment -> Contains the result of removing a comment from TestFile1.ans
#define SAUCE_REMOVECOMMENT_PATH            "expect/comment_remove/RemoveComment.ans"

// RemoveCommentAndAddEOF -> Contains the result of removing a comment from SauceButNoEOF.ans
#define SAUCE_REMOVECOMMENTANDADDEOF_PATH   "expect/comment_remove/RemoveCommentAndAddEOF.ans"


// The expected result of SAUCE_set_default
extern const SAUCE default_record;


#define TESTFILE1_EXPECTED_LINES    2

SAUCE* test_get_testfile1_expected_record();

char* test_get_testfile1_expected_comment();

SAUCE* test_get_testfile2_expected_record();

SAUCE* test_get_testfile3_expected_record();


// Test if a file's contents match another file's contents.
// Return true on a complete match, false if otherwise.
int test_file_matches_expected(const char* actual_filepath, const char* expected_filepath);

// Test if a buffer's contents match another file's contents.
// Return true on a complete match, false if otherwise.
int test_buffer_matches_expected(const char* buffer, uint32_t n, const char* expected_filepath);

// Copy a file from a src file to a dest file. Return 0 on success
int copy_file(const char* src, const char* dest);

// Copy the contents of a src file to a buffer. Return total bytes read on success.
int copy_file_into_buffer(const char* srcFile, char* buffer);

#endif //SAUCE_TEST_RES_HEADER_INCLUDED