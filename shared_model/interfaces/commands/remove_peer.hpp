/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_SHARED_MODEL_REMOVE_PEER_HPP
#define IROHA_SHARED_MODEL_REMOVE_PEER_HPP

#include "interfaces/base/noncopyable_model_primitive.hpp"

#include "interfaces/common_objects/peer.hpp"
#include "interfaces/common_objects/types.hpp"

namespace shared_model {
  namespace interface {

    /**
     * Remove a peer from Iroha
     */
    class RemovePeer : public NonCopyableModelPrimitive<RemovePeer> {
     public:
      /**
       * Return public key of peer to be removed by the command.
       */
      virtual const interface::types::PubkeyType &pubkey() const = 0;

      std::string toString() const override;

      bool operator==(const ModelType &rhs) const override;
    };
  }  // namespace interface
}  // namespace shared_model

#endif  // IROHA_SHARED_MODEL_REMOVE_PEER_HPP
