/*

 pinning_utils.h
 TrustKit

 Copyright 2023 The TrustKit Project Authors
 Licensed under the MIT license, see associated LICENSE file for terms.
 See AUTHORS file for the list of project authors.

 */

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

#if __has_feature(modules)
@import Security;
#else
#import <Security/Security.h>
#endif


#ifndef TrustKit_pinning_utils_h
#define TrustKit_pinning_utils_h

/**
 Evaluate trust for the specified certificate and policies
 
 This function invokes SecTrustEvaluateWithError() on iOS12+, macOS14+ and SecTrustEvaluate() otherwise.
 
 @param trust The trust management object to evaluate
 @param trsustResult On return, points to a result type reflecting the result of this evaluation.
 @param error An error pointer the method uses to return an error when trust evaluation fails. Set to nil to ignore the error.
 @return A boolean value indicating whether the certificate is trusted
 */
bool evaluateTrust(SecTrustRef serverTrust, SecTrustResultType *trustResult, NSError **error);

/**
 Returns a specific certificate from the certificate chain used to evaluate trust.
 
 This function invokes SecTrustCopyCertificateChain() on iOS 15+, macOS 12+ and SecTrustGetCertificateAtIndex() otherwise
 @param serverTrust The trust management object to evaluate
 @param index The index of the certificate to return
 @return A certificate object for the requested certificate.
 */
SecCertificateRef getCertificateAtIndex(SecTrustRef serverTrust, CFIndex index);

#endif
